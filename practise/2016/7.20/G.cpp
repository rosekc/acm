#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>

using namespace std;

bool cmp( char a, char b )
{
    return a > b;
}

int pow( int a, int b )
{
    if ( b == 1 ) return a;
    return a * pow( a, b - 1 );
}

char b[ 30 ];
char vis[ 30 ];
char re[ 6 ];
int c = int( 'A' ) - 1;
int a;

bool check()
{
    return a == ( int( b[ re[ 0 ] ] ) - c ) - pow( ( int( b[ re[ 1 ] ] ) - c ), 2 )
           + pow( ( int( b[ re[ 2 ] ] ) - c ), 3) - pow( ( int( b[ re[ 3 ] ] ) - c ), 4 )
           + pow( ( int( b[ re[ 4 ] ] ) - c ), 5 );
}

bool dfs( int in, int con )
{
    vis[ in ] = 1;

    if ( con == 5 )
    {
        //for ( int i = 0; i < 5; i++ )
        //{
        //    cout << b[ re[ i ] ];
        //}
        //cout << ( int( b[ re[ 0 ] ] ) - c ) - pow( ( int( b[ re[ 1 ] ] ) - c ), 2 )
        //     + pow( ( int( b[ re[ 2 ] ] ) - c ), 3) - pow( ( int( b[ re[ 3 ] ] ) - c ), 4 )
        //     + pow( ( int( b[ re[ 4 ] ] ) - c ), 5 ) << endl;

        if ( check() )
        {
            return 1;
        }
        else
        {
            vis[ in ] = 0;
            return 0;
        }
    }

    for ( int i = 0; i < strlen( b ); i++ )
    {
        //cout << tr<<" "<< tc<<"\n";
        //cout << vis[ tr ][ tc ] << "\n";

        //cout << (tr >= 0 && tr < r)<< endl;

        if ( vis[ i ] == 0 )
        {
            re[ con ] = i;
            if ( dfs( i, con + 1 ) ) return 1;
        }
    }
    vis[ in ] = 0;
    return 0;
}

int main()
{
    while ( cin >> a >> b && ( a != 0 || strcmp( "END", b ) != 0 ) )
    {
        bool flag = 0;
        sort( b, b + strlen( b ), cmp );
        //cout << b << endl;
        memset( vis, 0, strlen( b ) );
        for ( int i = 0; i < strlen( b ); i++ )
        {
            re[ 0 ] = i;
            if ( dfs( i, 1 ) )
            {
                flag = 1;
                break;
            }
        }
        if ( flag )
        {
            for ( int i = 0; i < 5; i++ )
            {
                cout << b[ re[ i ] ];
            }
            cout << endl;
        }
        else cout << "no solution\n";

    }
}
