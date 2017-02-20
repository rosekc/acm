#include <cstdio>

using namespace std;

int main()
{

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
			if ( i * i * i++ >= in ) break;
		}

		i--;

		printf( "%d\n", i );
	}
}
