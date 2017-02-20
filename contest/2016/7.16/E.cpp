#include <cstdio>

using namespace std;

int data[ 10005 ];
bool table[ 1000000 ];

int main()
{
	int n = 40000;
	int con = 1;
	for ( int i = 2; i <= n; i++ )
	{
		table[ i ] = 1;
	}

	for ( int i = 2; i <= n; i++ )
	{
		if ( table[ i ] )
		{
			data[ con++ ] = i;

			int j = i + 1;

			int con1 = 0;

			while ( 1 )
			{
				while ( table[ j ] == 0 && j <= n ) j++;
				if ( j > n ) break;
				con1++;
				if ( con1 == i )
				{
					table[ j ] = 0;
					con1 = 0;
				}
				j++;
			}
		}
	}
/*
	for ( int i = 1; i <= 3000; i++ )
	{
		printf("%d %d\n", i, data[ i ]);
	}
*/
	int in;

	while ( scanf( "%d", &in ) != EOF && in != 0 )
	{
		printf("%d\n", data[ in ] );
	}
}
