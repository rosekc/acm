#include <cstdio>

int main()
{
    int n;
    while ( scanf( "%d", &n ) != EOF )
    {
        n % 4 == 2 ? printf( "yes\n" ) : printf( "no\n" );
    }
}
