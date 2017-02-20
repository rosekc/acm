#include <cstdio>
#include <cmath>

using namespace std;

int ad[ 5000000 ];
int cd[ 5000000 ];

int main()
{
    int t;
    long long a, b, c;
    scanf("%d", &t );

    while ( t-- )
    {
        int flag = 0;
        int cona = 0;
        int conc = 0;
        scanf( "%I64d%I64d%I64d", &a, &b, &c );

        for( int i = 1; i <= a; i++ )
        {
            if( a % i == 0 )
            {
                ad[ cona++ ] = i;
            }
        }

        for( int i = 1; i <= c; i++ )
        {
            if( c % i == 0 )
            {
                cd[ conc++ ] = i;
            }
        }

        for( int i = 0; i < cona; i++ )
        {
            for( int j = 0; j < conc; j++ )
            {
                if( ad[ i ] * cd[ j ] + ( ( a / ad[ i ] ) * ( c / cd[ j ] ) ) == b )
                {
                    flag = 1;
                    break;
                }
            }
            if( flag == 1 ) break;
        }
        if( flag == 1 ) printf("YES\n");
        else printf( "NO\n");
    }
}
