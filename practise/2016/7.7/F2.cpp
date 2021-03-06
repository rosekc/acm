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
        int k = 1;
        int l = 1;

        while ( 1 )
        {
            if( tih[ i ] > kih[ j ] )
            {
                con1++;
                i++;
                j++;
            }
            else if( tih[ i ] == kih[ j ] )
            {
                if( tih[ n - k ] > kih[ n - l ] )
                {
                    con1++;
                    k++;
                    l++;
                }
                else
                {
                    if( tih[ n - k ] == kih[ j ] )
                    {
                        con2++;
                    }
                    j++;
                    k++;
                }
            }
            else
            {
                j++;
                k++;
            }
            if( i + k - 1 == n )
            {
                break;
            }
        }
        //printf( "%d\t%d\n", con1, con2 );
        printf( "%d\n", ( 2 * con1 - n + con2 ) * 200 );
    }
}
