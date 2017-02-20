//hdu 1128 Self Numbers
#include <stdio.h>
#include <string.h>

using namespace std;

int dn( int in )
{
    int sum = in;

    while( in >= 10 )
    {
        sum += in % 10;
        in /= 10;
    }

    return sum + in;
}

bool re[ 1000005 ];

int main()
{
    memset( re, 0, sizeof( re ) );
    for( int i = 1; i <= 1000000; i++ )
    {
        re[ dn( i ) ] = 1;
    }

    for( int i = 1; i <= 1000000; i++ )
    {
        if( re[ i ] == 0 )
        {
            printf( "%d\n", i );
        }
    }

}
