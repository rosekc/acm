#include <algorithm>
#include <cstdio>
using namespace std;
const int lmax = 10000;
int c1[lmax + 1], c2[lmax + 1];
int main()
{
    int a, b, c;
    while ( scanf( "%d%d%d", &a, &b, &c ) != EOF && a + b + c != 0 )
    {
        for(int i = 0; i <= a; i++ )
        {
            c1[ i ] = 1;
        }

        for( int i = 0; i <= lmax; i++ )
        {
            c2[ i ] = 0;
        }

        for( int i = 0; i <= a; i++ )
        {
            for ( int k = 0; k <= 2 * b; k += 2 )
            {
                c2[ i + k ] += c1[ i ];
            }
        }

        for( int i = 0; i <= a + 2 * b ; i++ )
        {
            c1[ i ] = c2[ i ];
            c2[ i ] = 0;
        }

        for( int i = 0; i <= a + 2 * b; i++ )
        {
            for ( int k = 0; k <= 5 * c; k += 5 )
            {
                c2[ i + k ] += c1[ i ];
            }
        }

        int i = 1;

        while( c2[ i ] != 0 ) i++;

        printf( "%d\n", i );
    }
}
