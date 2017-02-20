#include <cstdio>
#include <algorithm>

using namespace std;

int tih[ 1005 ];
int kih[ 1005 ];
int re[ 1005 ];

bool cmp( int &a, int &b )
{
    return a > b;
}

int main()
{
    int n;
    int con1;
    int con2;

    while ( scanf( "%d", &n ) != EOF && n != 0 )
    {
        con1 = 0;
        con2 = 0;

        for( int i = 0; i < n; i++ )
        {
            scanf( "%d", &tih[ i ] );
        }
        for( int i = 0; i < n; i++ )
        {
            scanf( "%d", &kih[ i ] );
        }

        sort( tih, tih + n, cmp );
        sort( kih, kih + n, cmp );

        int i = 0;
        int j = 0;

        while ( 1 )
        {
            if( tih[ i ] > kih[ j ] )
            {
                re[ j ] = 1;
                con1++;
                i++;
                j++;
            }
            else if( tih[ i ] == kih[ j ] )
            {
                int a = 1;
                while( j + a != n  && tih[ i ] == kih[ j + a ] )
                {
                    a++;
                }
                if( ( tih[ i + 1 ] > kih[ j + a ] && kih[ j + a ] != kih[ j + a + 1 ] ) || j + a == n )
                {
                    con2++;
                    i++;
                    j++;
                }
                else
                {
                    j++;
                }
            }
            else
            {
                re[ j ] = 0;
                j++;
            }
            if( j == n )
            {
                break;
            }
        }
        //printf( "%d\t%d\n", con1, con2 );
        printf( "%d\n", ( 2 * con1 - n + con2 ) * 200 );
    }
}
