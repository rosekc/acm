#include <cstdio>

int main()
{
	int n;

	while ( scanf( "%d", &n ) != EOF )
	{
		if ( n == 1 || n % 2 == 0 )
		{
			printf( "2^? mod %d = 1\n", n );
		}
		else
		{
			int i = 2;
			int tmp = 4;
			while( 1 )
            {
                if( tmp % n == 1 )
                {
                    break;
                }
                tmp = ( ( tmp % n ) * ( 2 % n ) );
                i++;
            }
            printf( "2^%d mod %d = 1\n", i, n );
		}
	}
}
