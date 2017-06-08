#include <stdio.h>

int findr( int u[], int a )
{
    int tmp = u[ a ];
    //printf( "%d\n", tmp );
    while( u[ tmp ] != tmp )
    {
        tmp = u[ tmp ];
    }
    u[ a ] = tmp;
    //printf( "%d\n", tmp );
    return tmp;
}

void connect( int u[], int a, int b )
{
    u[ findr( u, a ) ] = findr( u, b );
    //printf( "%d\n%d\n", findr( u, a ), u[ 1 ] );
}

int main()
{
    int n, m;
    int t1, t2;

    while( scanf( "%d", &n ) != EOF && n != 0 )
    {
        scanf( "%d", &m );
        int u[ n + 1 ];
        int con = 0;
        for( int i = 1; i <= n; i++ )
        {
            u[ i ] = i;
        }

        for( int i = 1; i <= m; i++ )
        {
            scanf( "%d%d", &t1, &t2 );
            connect( u, t1, t2 );
        }

        for( int i = 1; i <= n; i++ )
        {
            if( u[ i ] == i )
            {
                con++;
            }
            //printf( "%d\t%d\n", i, u[ i ] );
        }
        printf( "%d\n", con - 1 );
    }
}
