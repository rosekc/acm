#include <iostream>
using namespace std;

const int MAX = 1005;
char b[ MAX ][ MAX ];
int br[ MAX ];
int bc[ MAX ];
int r, c;

int main()
{
    while (cin >> r >> c )
    {
        int con = 0;
        bool flag = 0;
        int tr, tc;

        for (int i = 1; i <= r; i++ )
        {
            br[i] = 0;
        }
        for (int i = 1; i <= c; i++ )
        {
            bc[i] = 0;
        }

        for (int i = 1; i <= r; i++ )
        {
            for ( int j = 1; j <= c; j++ )
            {
                cin >> b[ i ][ j ];;
                if ( b[i][j] == '*' )
                {
                    br[i]++;
                    bc[j]++;
                    con++;
                }
            }
        }
        for (int i = 1; i <= r; i++ )
        {
            for ( int j = 1; j <= c; j++ )
            {
                if ( b[i][j] == '*' && con == br[i] + bc[j] - 1 )
                {
                    flag = 1;
                    tr = i;
                    tc = j;
                    break;
                }
                if ( b[i][j] != '*' && con == br[i] + bc[j] )
                {
                    flag = 1;
                    tr = i;
                    tc = j;
                    break;
                }
            }
            if ( flag ) break;
        }
        if ( flag )
        {
            cout << "YES\n";
            cout << tr << " " << tc << endl;
        }
        else cout << "NO\n";
    }
}
