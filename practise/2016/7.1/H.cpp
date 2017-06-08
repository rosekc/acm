#include <iostream>

using namespace std;

int main()
{
    int n, m, tmp;

    cin >> n;

    for( int i = 1; i <= n; i++ )
    {
        cin >> m;
        for( int j = 1; j <= m; j++ )
        {
            cin >> tmp;
        }
        if( m == 1 )
        {
            cout << tmp << endl;
        }
        else
        {
            cout << "0" << endl;
        }
    }
}
