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
            else
            {
                re[ j ] = 0;
                j++;
            }
            if( j == n )
            {
                while( j - 1 >= 0  && re[ j - 1 ] == 0 && tih[ i ] == kih[ j - 1 ] )
                {
                    j--;
                }
                while( j != n )
                {
                    if( tih[ i ] == kih[ j ] )
                    {
                        i++;
                        j++;
                        con2++;
                    }
                }
                break;
            }
        }
        //printf( "%d\t%d\n", con1, con2 );
        printf( "%d\n", ( 2 * con1 - n + con2 ) * 200 );
    }
}
