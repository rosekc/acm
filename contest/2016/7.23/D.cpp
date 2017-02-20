#include <cstdio>

using namespace std;

int n;
struct data
{
    bool t;
    int p;
};

data d[ 220050 ];
char c[ 220050 ];

int main()
{
    while ( scanf( "%d", &n ) != EOF )
    {
        //printf( "%d\n", n );

        //getchar();
        int tr = 1500000000;
        scanf( "%s", c );



        for ( int i = 0; i < n; i++ )
        {
            if ( c[ i ] == 'R' )
            {
                d[ i ].t = 1;
                if ( tr > i ) tr = i;
            }
            else d[ i ].t = 0;
            scanf( "%d", &d[i].p );
        }

        //sort( d, d + n, cmp );

        int mind = 1500000000;

        bool flag = 0;
        int tmp;

        for ( int i = tr; i < n; i++ )
        {
            bool flag1 = 0;
            if ( d[i].t == 1 )
            {
                for ( int j = i + 1; j < n; j++ )
                {
                    if ( d[j].t == 0 )
                    {
                        flag1 = 1;
                        tmp = j;
                        if ( d[j].p - d[j - 1].p < mind )
                        {
                            mind = d[j].p - d[ j - 1 ].p;
                            flag = 1;
                            //printf( "%d %d\n", i, j );
                        }
                        break;
                    }
                }
                if ( flag1 ) i = tmp;
                else break;
            }
        }

        if ( flag )
        {
            printf( "%d\n", ( mind + 1 ) / 2 );
        }
        else
        {
            printf( "-1\n" );
        }
    }
}
