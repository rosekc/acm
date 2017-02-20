#include <iostream>
#include <string>
using namespace std;

int f1( int in, int a, int b )
{
    if( in > 96 )
    {
        in %= 96;
    }
    if( in == 0 )
    {
        in += 96;
    }
    if( in == 1 || in == 2 )
    {
        return 1;
    }
    else
    {
        int n = 1, m = 1;
        int tmp;
        for( int i = 0; i < in - 2; i++ )
        {
            tmp = m;
            m =  ( m * a + n * b ) % 7;
            n = tmp;
        }
        return m;
    }
}


int main()
{
    int a, b, n;
/*
    for( int i = 1; i <= 96 * 3; i++ )
    {
        cout << i << "\t" <<f1( i, 2, 3 ) << endl;
    }
*/
    cin >> a >> b >> n;

    while( a + b + n != 0 )
    {
        cout << f1( n, a, b ) << endl;
        cin >> a >> b >> n;
    }
}
