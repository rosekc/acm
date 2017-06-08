#include <stdio.h>
#include <algorithm>

using namespace std;

int data[ 10005 ];

int main()
{
    int n, q;
    int tmp;
    int con = 1;

    while( scanf( "%d%d", &n, &q ) != EOF && n + q != 0 )
    {
        printf( "CASE# %d:\n", con++ );

        for( int i = 0; i < n; i++ )
        {
            scanf( "%d", &data[ i ] );
        }

        sort( data, data + n );

        for( int i = 0; i < q; i++ )
        {
            scanf( "%d", &tmp );
            for( int j = 0; j < n; j++ )
            {
                if( data[ j ] == tmp )
                {
                    printf( "%d found at %d\n", tmp, j + 1 );
                    break;
                }
                if( j == n - 1 )
                {
                    printf( "%d not found\n", tmp );
                }
            }
        }
    }
}
