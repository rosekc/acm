#include <cstdio>

int main()
{
	int n;

	while ( scanf( "%d", &n ) != EOF )
	{
		for ( int i = 1;; i += 2 )
		{
		    if( n <= i )
            {
                n % i == 0 ? printf( "1\n" ) : printf( "0\n" );
                break;
            }
            n -= i;
		}
	}
}
