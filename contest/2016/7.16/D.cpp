#include <cstdio>

using namespace std;

int data[ 1010 ];

int main()
{
    data[ 1 ] = 1;
	for ( int i = 2; i <= 400; i++ )
	{
		data[ i ] = i * i * i + data[ i - 1 ];
		//printf("%d\n", data[ i ]);
	}

	int t;

	scanf( "%d", &t );

	while ( t-- )
	{
		int in;
		int i = 1;

        scanf( "%d", &in );

        if( in <= 0 )
        {
            printf( "0\n" );
            continue;
        }
		for ( ;; )
		{
			if ( data[ i++ ] >= in ) break;
		}

		printf( "%d\n", --i );
	}


}
