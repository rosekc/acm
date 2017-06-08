#include <cstdio>
#include <string.h>

bool data[ 10005 ];

int main()
{
    memset( data, 1, sizeof( data ) );

    data[ 1 ] = 0;

    int i = 2;
    int n;

    while( i < 10005 / 2 )
    {
        for( int j = 2; i * j <= 10005; j++ )
        {
            data[ i * j ] = 0;
        }
        do
        {
            i++;
        }while( data[ i ] != 1 );
    }

    while ( scanf( "%d", &n ) != EOF && n != 0 )
    {
        int con = 0;
        for( int j = 3; j < n / 2; j++ )
        {
            if( data[ j ] == 0 )
            {
                continue;
            }
            if( data[ n - j ] == 1 )
            {
                con++;
                //printf( "%d\t%d\n", j, n - j );
            }
        }
        printf( "%d\n", con );
    }
}
