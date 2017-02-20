#include <stdio.h>

using namespace std;

struct data
{
	int num = 0;
	int con = 0;
};


int tmp;

data a[ 1000000 ];

int main()
{
	int t;
	int con;

	while ( scanf( "%d", &t ) != EOF && t != 0 )
	{
		scanf( "%d", &tmp );
		a[ 0 ].con = 1;
		a[ 0 ].num = tmp;
		con = 1;

		for( int i = 1; i < t; i++ )
		{
			scanf( "%d", &tmp );
			for( int j = 0; j < con; j++ )
			{
				if( tmp == a[ j ].num )
				{
					a[ j ].con++;
					//printf( "233\n" );
					break;
				}
				if( j == con - 1 )
				{
					a[ con ].con = 1;
					a[ con ].num = tmp;
					con++;
					break;
				}
			}
		}
		for( int j = 0; j < con; j++ )
		{
		    //printf( "%d\t%d\n", a[ j ].num, a[ j ].con );
			if( 1 == a[ j ].con )
			{
				printf( "%d\n", a[ j ].num );
				break;
			}
		}
	}
}

