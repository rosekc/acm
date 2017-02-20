#include <cstdio>
#include <cmath>

using namespace std;

bool data[ 20000 ];
int status[ 20000 ];
int out[ 20000 ];

int main()
{
	int n;
	int t;

	while ( scanf( "%d", &n ) != EOF )
	{
		int max2;
		int con = 0;
		int flag = 0;
		for ( int i = 1; i <= 100 * n; i++ )
		{
			data[ i ] = 0;
			status[ i ] = 40000;
		}

		scanf( "%d", &t );
		data[ t ] = 1;
		status[ t ] = 1;
		max2 = t;

		for ( int i = 2; i <= n; i++ )
		{
			scanf( "%d", &t );
			max2 += t;
			if ( data[ t ] == 0 ) status[ t ] = i;
			data[ t ] = 1;
			//printf("6\n");
			if ( t > max2 ) max2 = t;
			//printf("       %d\n", data[ t ] );
			//int max1;
			for ( int j = 1; j <= max2; j++ )
			{
				if ( data[ j ] == 1 && status[ j ] < i )
				{
					//printf("              %d\n", max2);
					if ( data[ j + t ] == 0 ) status[ j + t ] = i;
					data[ j + t ] = 1;

					int tmp = abs( j - t );

					if ( data[ tmp ] == 0 ) status[ tmp ] = i;
					data[ tmp ] = 1;

					//if ( j + t > max2 )
					//{
					//  max1 = j + t;
					//  flag = 1;
					//}
				}
			}
			//if ( flag == 1 ) max2 = max1;
		}

		//printf( "%d \n", max2 );

		for ( int i = 1; i <= max2; i++ )
		{
			//printf( "%d ", data[ i ] );
			//printf( "%d\n", status[ i ] );
			if ( data[ i ] == 0 )
			{
				out[ con++ ] = i;
			}
		}
		printf( "%d\n", con );
		for ( int i = 0; i < con; i++ )
		{
			printf( "%d", out[ i ] );
			if ( i < con ) printf(" ");
		}
		if (con > 0) printf( "\n");
	}
}
