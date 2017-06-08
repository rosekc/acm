#include <cstdio>

bool data[ 10005 ];

int main()
{
    int n, m, a;

    data[ 1 ] = 0;

    for( int i = 2; i < 10000; i++ )
    {
        int sum = 1;
        for( int j = 2; j <= i / 2; j++ )
        {
            if( i % j == 0 )
            {
                sum += j;
            }
        }
        if( sum == i )
        {
            data[ i ] = 1;
        }
        else
        {
            data[ i ] = 0;
        }
    }

    scanf( "%d", &a );

    for( int j = 0; j < a; j++ )
    {
        scanf( "%d%d", &n, &m );

        int con = 0;
        if( n > m )
        {
            int tmp = n;
            n = m;
            m = tmp;
        }
        for( int i = n; i <= m; i++ )
        {
            if( data[ i ] )
            {
                con++;
            }
        }
        printf( "%d\n", con );
    }
}
