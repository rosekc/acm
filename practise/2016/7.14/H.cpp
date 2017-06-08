#include <cstdio>

using namespace std;

int main()
{
    int d, l, v1, v2;

    while ( scanf( "%d%d%d%d", &d, &l, &v1, &v2 ) != EOF )
    {
        printf( "%.20lf\n", double( l - d ) / double( v1 + v2 ) );
    }
}
