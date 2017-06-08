#include <iostream>

using namespace std;

const int tmax = 105;
const int wr[ 8 ] = { -1, -1, 0, 1, 1, 1, 0, -1 };
const int wc[ 8 ] = { 0, 1, 1, 1, 0, -1, -1, -1 };
char lab[ tmax ][ tmax ];
int vis[ tmax ][ tmax ];

int re, ce;

void dfs( int r, int c )
{
    vis[ r ][ c ] = 1;

	for ( int i = 0; i < 8; i++ )
	{
		int tr = r + wr[ i ];
		int tc = c + wc[ i ];

        //cout << tr<<" "<< tc<<"\n";
        //cout << vis[ tr ][ tc ] << "\n";

        //cout << (tr >= 0 && tr < r)<< endl;

		if ( tr >= 0 && tr < re &&
		        tc >= 0 && tc < ce && lab[ tr ][ tc ] == '@' && vis[ tr ][ tc ] == 0 )
		{
            //cout << tr<<" "<< tc << " " << t <<"\n";
			dfs( tr, tc );
		}
	}
}

int main()
{
	int t;
	int sr, sc;
	int er, ec;

	while ( cin >> re >> ce && ce != 0)
	{
	    int con = 0;
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
			    if( vis[ i ][ j ] == 0 && lab[ i ][ j ] == '@' )
                {
                    //cout <<"1\n";
                    dfs( i, j );
                    con++;
                }
			}
		}

		cout <<  con << endl;
	}
}
