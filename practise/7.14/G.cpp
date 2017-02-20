#include <cstdio>

using namespace std;

int main()
{

    int n, m, k;
    int a, b;
    int c1;


    while ( scanf( "%d%d%d", &n, &m, &k ) != EOF )
    {
        int r[ n + 1 ][ 2 ];
        int c[ m + 1 ][ 2 ];

        for( int i = 1; i <= n; i++ )
        {
            r[ i ][ 0 ] = 0;
            r[ i ][ 1 ] = 0;
        }

        for( int i = 1; i <= m; i++ )
        {
            c[ i ][ 0 ] = 0;
            c[ i ][ 1 ] = 0;
        }

        int t = 0;

        while ( t++ < k )
        {
            scanf( "%d%d%d", &a, &b, &c1 );

            if( a == 1 )
            {
                r[ b ][ 0 ] = t;
                r[ b ][ 1 ] = c1;
            }
            else
            {
                c[ b ][ 0 ] = t;
                c[ b ][ 1 ] = c1;
            }
        }

        for( int i = 1; i <= n; i++ )
        {
            for ( int j = 1; j <= m; j++ )
            {
                printf( "%d ", r[ i ][ 0 ] > c[ j ][ 0 ] ? r[ i ][ 1 ] : c[ j ][ 1 ] );
            }
            printf( "\n" );
        }
    }
}
