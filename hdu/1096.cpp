//hduacm 1096
#include <iostream>
using namespace std;

int main()
{
    int n, a, b, c;

    cin >> c;

    for( int j = 1; j <= c; j++ )
    {
        b = 0;

        cin >> n;

        for( int i = 1; i <= n; i++ )
        {
            cin >> a;
            b += a;
        }

        cout << b << endl;

        if( j <= c  )
        {
            cout << endl;
        }
    }
}
