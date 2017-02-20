//hduacm 1092
#include <iostream>
using namespace std;

int main()
{
    int n, a, b;

    while( cin >> n && n )
    {
        b = 0;

        for( int i = 1; i <= n; i++ )
        {
            cin >> a;
            b += a;
        }

        cout << b << endl;
    }
}
