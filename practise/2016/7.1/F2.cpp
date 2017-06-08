//F - Machine
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <memory.h>

using namespace std;

stringstream ss;

void f1( int64_t in )
{
	if( in < 3 )
	{
		ss << in;
	}
	else
	{
		f1( in / 3 );
		ss << in % 3;
	}
}

int main()
{
	int t, m;
	int64_t n;

	cin >> t;

	for( int i = 1; i <= t; i++ )
	{
		cin >> m >> n;

		int64_t tmp = pow( 3, m );
		n %= tmp;

		ss.clear();
		f1( n );
		string s;
		ss >> s;

		//cout << s << endl;

		for( int j = 1; j <= m - s.size(); j++ )
        {
            cout << 'R';
        }

		for( int j = 0; j < s.size(); j++ )
		{
			if( s.at( j ) == '0' )
            {
                //cout << j <<endl;
                cout << 'R';
            }
            else
            {
                if( s.at( j ) == '1' )
                {
                    //cout << j <<endl;
                    cout << 'G';
                }
                else if( s.at( j ) == '2' )
                {
                    cout << 'B';
                }
            }
		}
		cout << endl;
	}

}
