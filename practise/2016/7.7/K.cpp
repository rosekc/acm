#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

struct rider
{
    int v;
    int t;
    int res;
};

bool cmp( rider a, rider b )
{
    if( a.t < 0 )
    {
        return 0;
    }
    if( b.t < 0 )
    {
        return 1;
    }
    return a.res < b.res;
}

rider data[ 20005 ];

int main()
{
    int n;
    int t = 0;

    while ( scanf( "%d", &n ) != EOF && n != 0 )
    {
        for( int i = 0; i < n; i++ )
        {
            scanf( "%d%d", &data[ i ].v, &data[ i ].t );
            data[ i ].res = data[ i ].t + ceil( double( 16200 ) / double( data[ i ].v ) );
        }

        sort( data, data + n, cmp );

        printf( "%d\n", data[ 0 ].res );
    }
}
