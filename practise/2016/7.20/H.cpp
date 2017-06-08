#include <cstdio>

using namespace std;

int main()
{
    int t, a, b, c;

    scanf( "%d", &t );

    while( t-- )
    {
        scanf( "%d%d%d", &a, &b, &c );

        if( c % 2 )
        {
            printf( "Impossible\n");
        }
        else
        {
            c /= 2;
            bool flag = 0;
            bool flag1 = 0;
            int i = 0;
            int j = 0;
            if( a > b )
            {
                int tmp = a;
                a = b;
                b = tmp;
                flag1 = 1;
            }
            for( ;; i++ )
            {
                for( j = 0;; j++ )
                {
                    //printf( "%d %d\n", i * 2, j * 2 );
                    if( a * i + b * j == c )
                    {
                        flag = 1;
                        break;
                    }
                    else if( a * i + b * j > c ) break;
                }
                if( a * i > c || flag ) break;
            }
            if( flag )
            {
                if( flag1 ) printf( "%d %d\n", j * 2, i * 2 );
                else printf( "%d %d\n", i * 2, j * 2 );
            }
            else
            {
                printf( "Impossible\n");
            }
        }
    }
}
