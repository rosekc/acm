#include <cstdio>

using namespace std;

int main()
{
    int n, h;
    int a;

    while( scanf( "%d%d", &n, &h ) != EOF )
    {
        int sum = 0;
        for ( int i = 1; i <= n; i++ )
        {
            scanf( "%d", &a );
            if( a > h )
            {
                sum++;
            }
        }
        printf( "%d\n", sum + n );
    }
}
