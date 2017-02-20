#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;
    int a, c;
    string b;

    while( 1 )
    {
        cin >> n >> m;

        if( m == 0 )
        {
            break;
        }

        vector av< int > ( n );//a vector!!!
        vector bv< string > ( n );
        vector cv< int > ( n );
        vector tmpint< int >;
        vector tmpstr< string >;

        for( int i = 0; i < n; i++ )
        {
            cin >> a >> b >> c;
            av.at( i ) = a;
            bv.at( i ) = b;
            cv.at( i ) = c;
        }

        if( m == 1 )
        {
            tmpint = av;
            sort( tmpint)
        }
    }

}
