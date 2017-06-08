#include <iostream>
#include <string>
using namespace std;

int main()
{
    string n, m;

    while( 1 )
    {
        int con = 0;
        cin >> n;
        if( n =="#" )
        {
            break;
        }

        cin >> m;

        for( int i = 0; i <= n.size() - m.size(); )
        {
            int flag = 0;
            for( int j = 0; j < m.size(); j++ )
            {
                if( n.at( i + j ) != m.at( j ) )
                {
                    //cout << j << endl;
                    flag = 1;
                    break;
                }
            }
            if( flag == 0 )
            {
                con++;
                i += m.size();
                continue;
            }
            i++;
        }
        cout << con << endl;
    }
}
