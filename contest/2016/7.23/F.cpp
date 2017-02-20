#include <cstdio>

using namespace std;

struct Point
{
    long long x;
    long long y;
};

unsigned long long dist( Point a, Point b )
{
    return ( a.x - b.x) * ( a.x - b.x) + ( a.y - b.y) * ( a.y - b.y );
}

Point d[ 2005 ];
int n, x1, x2, y1, y2;

int main()
{
    while ( scanf( "%d%d%d%d%d", &n, &x1, &y1, &x2, &y2 ) != EOF )
    {
        int tx, ty;
        unsigned long long r1 = 0;
        unsigned long long r2 = 0;

        for ( int i = 0; i < n; i++ )
        {
            scanf( "%d%d", &tx, &ty );
            unsigned long long td1 = dist( {tx,ty}, {x1, y1} );
            unsigned long long td2 = dist( {tx,ty}, {x2,y2});
            if( td1 - r1 < td2 - r2 )
            {
                if( td1 > r1 )
                {
                    r1 = td1;
                }
            }
            else
            {
                if( td2 > r2 )
                {
                    r2 = td2;
                }
            }
        }

        printf( "%I64u\n", r1 + r2 );
    }
}

