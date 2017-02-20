#include <cstdio>
#include <algorithm>

using namespace std;

int datan[ 10005 ];
int datam[ 10005 ];

int main()
{
	int n, m;
	int tmp;
	while ( scanf( "%d%d", &n, &m ) != EOF )
	{
		for ( int i = 0; i < n; i++ )
		{
			scanf( "%d", &datan[ i ] );
		}

		for ( int i = 0; i < m; i++ )
		{
			scanf( "%d", &datam[ i ] );
		}

		sort( datan, datan + n );
		sort( datam, datam + m );

		int i = 0, j = 0;

		while ( i < n || j < m )
		{
			while ( ( i < n && j < m && datan[ i ] < datam[ j ] ) || ( i < n && j == m ) )
			{
				printf( "%d", datan[ i ] );
				i++;
				if ( i < n || j < m )
				{
                    printf( " " );
				}
				else
                    break;
			}

			//printf( "%d", j );

			while ( i < n && j < m && datan[ i ] == datam[ j ] )
			{
				printf( "%d", datan[ i ] );
				i++;
				j++;
				if ( i < n || j < m )
				{
                    printf( " " );
				}
				else
                    break;
			}

			while ( ( i < n && j < m && datan[ i ] > datam[ j ] ) || ( j < m && i == n ) )
			{
				printf( "%d", datam[ j ] );
				j++;
				if ( i < n || j < m )
				{
                    printf( " " );
				}
				else
                    break;
			}
		}

		printf( "\n" );
	}
}
