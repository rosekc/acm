#include <cstdio>
#include <algorithm>

using namespace std;

int data[ 10005 ];

int main()
{
    int n, m;
    int con;
    int tmp;
    while( scanf( "%d%d", &n, &m ) != EOF )
    {
        con = n;
        for( int i = 0; i < n; i++ )
        {
            scanf( "%d", &data[ i ] );
        }

        for ( int i = 0; i < m; i++ )
        {
            scanf( "%d", &tmp );
            for ( int j = 0; j < con; j++ )
            {
                if( data[ j ] != tmp )
                {
                    data[ con++ ] = tmp;
                    break;
                }
            }
        }

        sort( data, data + con );

        for ( int i = 0; i < con; i++ )
        {
            printf( "%d", data[ i ] );
            if ( i != con - 1 )
            {
                printf( " " );
            }
        }
        printf( "\n" );
    }
}
