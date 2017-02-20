//hduacm 2000
#include <iostream>
using namespace std;

int main()
{
    char a, b, c;

    while( cin >> a >> b >> c )
    {
        if( a < b )
        {
            if( b < c )
            {
                cout << a << " " << b << " " << c << endl;
            }
            else if( a < c && b > c )
            {
                cout << a << " " << c << " " << b << endl;
            }
            else
            {
                cout << c << " " << a << " " << b << endl;
            }
        }
        else
        {
            if( b > c )
            {
                cout << c << " " << b << " " << a << endl;
            }
            else if( a > c && b < c )
            {
                cout << b << " " << c << " " << a << endl;
            }
            else
            {
                cout << b << " " << a << " " << c << endl;
            }

        }
    }
}
