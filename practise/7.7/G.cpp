#include <stdio.h>

int data[ 1005 ];
int re[ 1005 ];

int main()
{
    int t;
    int m, k;

    scanf( "%d", &t );

    while ( t-- )
    {
        long long maxi = 0;
        long long mini = 10000005;
        long long ind;
        int con = 0;

        scanf( "%d%d", &m, &k );

        for ( int i = 0; i < m; i++ )
        {
            scanf( "%d", &data[ i ] );
            maxi += data[ i ];
            if ( mini > data[ i ] ) mini = data[ i ];
        }



        while ( maxi >= mini )
        {
            int tind = ( maxi + mini ) / 2;
            long long tmp = 0;
            int i = 0;
            con = 0;

            //printf( "%ld  %ld  \n", maxi, mini );
            //printf( "%d\n",  tind );

            //printf( "     %ld\n", tind );

            while ( i < m && con < k )
            {
                while ( i < m && tmp + data[ i ] <= tind )
                {
                    tmp += data[ i++ ];
                    //printf( "  %d\n", tmp );
                }
                tmp = 0;
                con++;
            }

            //printf("%d %d\n", i, con);

            if ( con == k && i < m )
            {
                mini = tind + 1;
            }
            else if ( con <= k && i == m )
            {
                maxi = tind - 1;
                ind = tind;
                //printf( "%d\n", ind);
            }
        }

        //printf( "  %d\n", ind );

        long long tmp = 0;
        int i = m - 1;
        int j = k - 2;

        while ( i >= 0 )
        {
            while ( i >= 0 )
            {
                //printf( "       %d\n", ind );
                tmp += data[ i-- ];
                //printf( "  %d\n", tmp );
                if ( tmp + data[ i ] > ind ) break;

                if ( i == j )
                {
                    while ( j >= 0 )
                    {
                        re[ j-- ] = i--;
                        //printf( "  %d  %d\n", i, j );
                    }
                }
            }
            if ( i >= 0 && j >= 0 ) re[ j-- ] = i;
            tmp = 0;
            //printf( "  %d  %d\n", i, j );
        }

        con = 0;
        /*
                for ( int i = 0; i < k - 1; i++ )
                {
                    printf("%d ", re[i]);
                }
                printf( "\n");
        */

        for ( int i = 0; i < m; i++ )
        {
            printf( "%d", data[ i ] );
            if ( i < m )
            {
                printf( " " );
            }
            if ( con < k - 1 && re[ con ] == i )
            {
                printf( "/ " );
                con++;
            }
        }

        printf( "\n" );
    }
}
//5 5 1 5 5 4 9
