#include <cstdio>
#include <algorithm>

using namespace std;

int data[ 100005 ];

bool cmp( int a, int b )
{
    return a > b;
}

int main()
{
    int n, con;

    while ( scanf( "%d", &n ) != EOF )
    {
        con = 0;
        int tmp;
        unsigned long long sum = 0;

        while ( n-- )
        {
            scanf( "%d", &tmp );
            if( tmp % 2 == 0 )
            {
                sum += tmp;
            }
            else
            {
                data[ con++ ] = tmp;
            }
        }

        if( con % 2 == 0 )
        {
            for( int i = 0; i < con; i++ )
            {
                sum += data[ i ];
            }
        }
        else
        {
            sort( data, data + con, cmp );
            for( int i = 0; i < con - 1; i++ )
            {
                sum += data[ i ];
            }
        }


        printf( "%I64d\n", sum );
    }
}
