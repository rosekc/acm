#include <cstdio>

int data[ 55 ];

int main()
{
    int n, hi;
    int sum;
    int con;
    int cons = 1;

    while( scanf( "%d", &n ) != EOF && n != 0 )
    {
        sum = 0;
        con = 0;
        for( int i = 0; i < n; i++ )
        {
            scanf( "%d", &hi );
            data[ i ] = hi;
            sum += hi;
        }

        sum /= n;

        for( int i = 0; i < n; i++ )
        {
            if( data[ i ] > sum )
            {
                con += data[ i ] - sum;
            }
        }

        printf( "Set #%d\n", cons++ );
        printf( "The minimum number of moves is %d.\n\n", con );
    }
}
