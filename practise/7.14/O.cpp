#include <algorithm>
#include <cstdio>
using namespace std;
const int lmax = 250001;
int c1[lmax + 1], c2[lmax + 1];
int main()
{
	int t;
	while ( scanf( "%d", &t ) != EOF && t >= 0 )
	{
		for( int i = 0; i < lmax; i++ )
		{
		    c1[ i ] = 0;
			c2[ i ] = 0;
		}

		int n, m;
		int sum;

		scanf( "%d%d", &n, &m );

		sum = n * m;

		for(int i = 0; i <= sum; i += n )
		{
			c1[ i ] = 1;
		}


/*
		for( int i = 0; i <= sum; i++ )
		{
			printf( "%d ", c1[ i ]);
		}
		printf("\n");*/

		for ( int l = 2; l <= t; l++ )
		{
			scanf( "%d%d", &n, &m );



			for( int i = 0; i <= sum; i++ )
			{
				for ( int k = 0; k <= n * m; k += n )
				{
					c2[ i + k ] += c1[ i ];
				}
			}

			sum += n * m;

			for( int i = 0; i <= sum; i++ )
			{
				c1[ i ] = c2[ i ];
				c2[ i ] = 0;
			}
		}
/*
		for( int i = 0; i <= sum; i++ )
		{
			printf( "%d ", c1[ i ]);
		}

        printf( "\n");*/

		int tmp = ( sum + 1 ) / 2;
		while( c1[ tmp ] == 0 && c1[ sum - tmp ] == 0 ) tmp++;
		//printf( "%d\n",sum);
		printf( "%d %d\n", tmp, sum - tmp );
	}
}
