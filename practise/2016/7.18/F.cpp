#include <iostream>
using namespace std;

const int tmax = 60;
const bool wwall[ 16 ] = { 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1 };
const bool nwall[ 16 ] = { 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1 };
const bool ewall[ 16 ] = { 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1 };
const bool swall[ 16 ] = { 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1 };
const int wr[ 4 ] = { -1, 0, 1, 0 };
const int wc[ 4 ] = { 0, 1, 0, -1 };
int lab[ tmax ][ tmax ];
int vis[ tmax ][ tmax ];
int re, ce;

bool checkcnt( int &i, int &r, int &c,int &tr, int &tc )
{
    if( !( tr >= 0 && tr < re && tc >= 0 && tc < ce && vis[ tr ][ tc ] == 0 ) ) return 0;
    if( i == 0 && !nwall[ lab[ r ][ c ] ] && !swall[ lab[ tr ][ tc ] ] )
    {
        return 1;
    }
    else if( i == 1 && !ewall[ lab[ r ][ c ] ] && !wwall[ lab[ tr ][ tc ] ] )
    {
        return 1;
    }
    else if( i == 2 && !swall[ lab[ r ][ c ] ] && !nwall[ lab[ tr ][ tc ] ] )
    {
        return 1;
    }
    else if( i == 3 && !wwall[ lab[ r ][ c ] ] && !ewall[ lab[ tr ][ tc ] ] )
    {
        return 1;
    }
    return 0;
}

int dfs( int r, int c )
{
    vis[ r ][ c ] = 1;
    int con1 = 0;
    int con = 0;

    //cout << r << " " << c << endl;

	for ( int i = 0; i < 4; i++ )
	{
		int tr = r + wr[ i ];
		int tc = c + wc[ i ];

        //cout << tr<<" "<< tc<<"\n";
        //cout << vis[ tr ][ tc ] << "\n";

        //cout << (tr >= 0 && tr < r)<< endl;

		if ( checkcnt( i, r, c, tr, tc ) )
		{
            //cout << tr<<" "<< tc << " " << t <<"\n";
            con1++;
			con += dfs( tr, tc );
		}
	}
	return con + con1;
}

int main()
{
	while ( cin >> re >> ce )
	{
	    int con = 0;
	    int con1 = 0;
		//printf( "%d %d\n", r, c );

		for ( int i = 0; i < re; i++ )
		{
			for ( int j = 0; j < ce; j++ )
			{
			    vis[ i ][ j ] = 0;
				cin >> lab[ i ][ j ];
			}
		}

        for ( int i = 0; i < re; i++ )
		{
			for ( int j = 0; j < ce; j++ )
			{
			    if( vis[ i ][ j ] == 0 )
                {
                    //cout <<"1\n";
                    int tmp = dfs( i, j );
                    //cout << tmp << endl;
                    if( tmp > con1 ) con1 = tmp;
                    con++;
                }
			}
		}

		cout << con << endl;
		cout << con1 + 1 << endl;
	}
}
