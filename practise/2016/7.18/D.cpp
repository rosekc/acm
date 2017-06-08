#include <cstdio>
#include <string.h>

const int MAX = 200;
bool data[ 10005 ];
bool vis[ MAX ];
int res[ MAX ];
int n;

bool dfs( int i, int con )
{
	vis[ i ] = 1;
	res[ con ] = i;

	if( con == n )
	{
		if( data[ res[ con ] + res[ 1 ] ] == 1 )
        {
            vis[ i ] = 0;
            return 1;
        }
		else
		{
			vis[ i ] = 0;
			return 0;
		}
	}

	for( int j = 1; j <= n; j++ )
	{
		while( j <= n && ( vis[ j ] == 1 || data[ i + j ] == 0 ) )
		{
			j++;
		}
		if( j > n ) break;
		if( dfs( j, con + 1 ) == 1 )
		{
			for( int k = 1; k <= n; k++ )
			{
				printf( "%d", res[ k ] );
				if( k <= con ) printf( " " );
			}
			printf( "\n" );
		}
	}
	vis[ i ] = 0;
	return 0;
}

int main()
{
	memset( data, 1, sizeof( data ) );

	data[ 1 ] = 0;

	int i = 2;
	int c = 1;

	while( i < 10005 / 2 )
	{
		for( int j = 2; i * j <= 10005; j++ )
		{
			data[ i * j ] = 0;
		}
		do
		{
			i++;
		}
		while( data[ i ] != 1 );
	}

	//for( int i = 1; i <= 100; i++ )
	//    printf( "%d %d\n", i, data[ i ] );

	while ( scanf( "%d", &n) != EOF )
	{
	    printf( "Case %d:\n", c++ );
		dfs( 1, 1 );
		printf( "\n" );
	}
}
