#include <stdio.h>

/*
int f1( int* in, int x, int y, int s )
{
	for ( int i = 1; i <= s; i++ )
	{
		int tmp = in[ x ][ i ];
		in[ x ][ i ] = in [ y ][ i ];
		in[ y ][ i ] = tmp;
	}
}

int f2( int in[][ m + 1 ], int x, int y, int s )
{
	for ( int i = 1; i <= s; i++ )
	{
		int tmp = in[ i ][ x ];
		in[ i ][ x ] = in [ i ][ y ];
		in[ i ][ y ] = tmp;
	}
}

int f3( int in[][ m + 1 ], int x, int y, int s )
{
	for ( int i = 1; i <= s; i++ )
	{
		in[ x ][ i ] += y;
	}
}

int f4( int in[][ m + 1 ], int x, int y, int s )
{
	for ( int i = 1; i <= s; i++ )
	{
		in[ i ][ x ] += y;
	}
}
*/

int ma[ 1005 ][ 1005 ];

int main()
{
	int t;
	int n, m, q;
    int c, x, y;
    int tmp;


	scanf( "%d", &t );

	for ( int i = 1; i <= t; i++ )
	{
		scanf( "%d%d%d", &n, &m, &q );

		for ( int j = 1; j <= n; j++ )
		{
			for ( int k = 1; k <= m; k++ )
			{
				scanf( "%d", &ma[ j ][ k ] );
			}
		}

		for ( int j = 1; j <= q; j++ )
		{
			scanf( "%d%d%d", &c, &x, &y );

			switch ( c )
			{
			case 1:
				for ( int i = 1; i <= m; i++ )
				{
					tmp = ma[ x ][ i ];
					ma[ x ][ i ] = ma [ y ][ i ];
					ma[ y ][ i ] = tmp;
				}
				break;
			case 2:
				for ( int i = 1; i <= n; i++ )
				{
					tmp = ma[ i ][ x ];
					ma[ i ][ x ] = ma [ i ][ y ];
					ma[ i ][ y ] = tmp;
				}
				break;
			case 3:
				for ( int i = 1; i <= m; i++ )
				{
					ma[ x ][ i ] += y;
				}
				break;
			case 4:
				for ( int i = 1; i <= n; i++ )
				{
					ma[ i ][ x ] += y;
				}
				break;
			}
		}
		for ( int j = 1; j <= n; j++ )
		{
			for ( int k = 1; k <= m; k++ )
			{
				printf( "%d ", ma[ j ][ k ] );
			}
			printf( "\n" );
		}
	}
}
