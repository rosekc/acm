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

int u[ 1005 ];

int main()
{
    int n, m;
    int t;
    int t1, t2;

    scanf( "%d", &t );

    for ( int i = 0; i < t; i++ )
    {
        scanf( "%d%d", &n, &m );

        int con = 0;
        for( int j = 1; j <= n; j++ )
        {
            u[ j ] = j;
        }

        for ( int j = 0; j < m; j++ )
        {
            scanf( "%d%d", &t1, &t2 );
            connect( u, t1, t2 );
        }

        for( int j = 1; j <= n; j++ )
        {
            if( u[ j ] == j )
            {
                con++;
            }
            //printf( "%d\t%d\n", i, u[ i ] );
        }

        printf( "%d\n", con );
    }
}
