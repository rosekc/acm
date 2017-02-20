//Program M - »Àº˚»À∞ÆA+B
#include <stdio.h>

int main()
{
    int n, h1, m1, s1, h2, m2, s2;
    int h, m, s;

    scanf( "%d", &n );

    for( int j = 1; j <= n; j++ )
    {
        scanf( "%d%d%d%d%d%d", &h1, &m1, &s1, &h2, &m2, &s2 );

        s = s1 + s2;

        if( s >= 60 )
        {
            s %= 60;
            m1++;
        }

        m = m1 + m2;

        if( m >= 60 )
        {
            m %= 60;
            h1++;
        }

        h = h1 + h2;

        printf( "%d %d %d\n", h, m, s );


    }
}
