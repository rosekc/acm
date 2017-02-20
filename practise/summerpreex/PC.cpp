#include <iostream>
using namespace std;

int main()
{
    int n, u, d;

    cin >> n >> u >> d;

    while( n + u + d != 0 )
    {
        int m = 0;
        for( ; n > 0; m++ )
        {
            if( m % 2 == 0 )
            {
                n -= u;
            }
            else
            {
                n += d;
            }
        }
        cout << m << endl;

        cin >> n >> u >> d;
    }
}
