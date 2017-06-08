#include <iostream>
#include <cmath>

using namespace std;

const int wr[ 4 ] = { -1, 0, 1, 0 };
const int wc[ 4 ] = { 0, 1, 0, -1 };
char lab[ 20 ][ 20 ];
int vis[ 20 ][ 20 ];

int re, ce;

bool dfs( int r, int c, int t )
{
    vis[ r ][ c ] = 1;

    if ( lab[ r ][ c ] == 'D' && t != 0 )
	{
	    //cout << t <<"\n";
	    vis[ r ][ c ] = 0;
		return 0;
	}
	if ( lab[ r ][ c ] == 'D' && t == 0 )
	{
	    //cout << t <<"\n";
		return 1;
	}
	if ( t == 0 )
	{
	    vis[ r ][ c ] = 0;
		return 0;
	}
	for ( int i = 0; i < 4; i++ )
	{
		int tr = r + wr[ i ];
		int tc = c + wc[ i ];

        //cout << tr<<" "<< tc<<"\n";
        //cout << vis[ tr ][ tc ] << "\n";

        //cout << (tr >= 0 && tr < r)<< endl;

		if ( tr >= 0 && tr < re &&
		        tc >= 0 && tc < ce && ( lab[ tr ][ tc ] == '.' || lab[ tr ][ tc ] == 'D' ) && vis[ tr ][ tc ] == 0 )
		{
            //cout << tr<<" "<< tc << " " << t <<"\n";
			if ( dfs( tr, tc, ( t - 1 ) ) == 1 ) return 1;
		}
	}
	vis[ r ][ c ] = 0;
	return 0;
}

int dist( int sr, int sc, int er, int ec )
{
    return abs( sr - er ) + abs( sc - ec );
}

int main()
{
	int t;
	int sr, sc;
	int er, ec;

	while ( cin >> re >> ce >> t && re + ce + t != 0)
	{
		//printf( "%d %d\n", r, c );

		for ( int i = 0; i < re; i++ )
		{
			for ( int j = 0; j < ce; j++ )
			{
			    vis[ i ][ j ] = 0;
				cin >> lab[ i ][ j ];
				if ( lab[ i ][ j ] == 'S' )
				{
					sr = i;
					sc = j;
				}
				if ( lab[ i ][ j ] == 'D' )
				{
					er = i;
					ec = j;
				}
			}
		}

		if( dist( sr, sc, er, ec ) > t || ( t - dist( sr, sc, er, ec ) ) % 2 != 0 )
        {
            cout << "NO\n";
            continue;
        }

        //cout << "123\n";

		if ( dfs( sr, sc, t ) ) cout << "YES\n";
		else cout << "NO\n";
	}
}
