//F - Machine
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <memory.h>

using namespace std;

stringstream ss;

string f1( int64_t in )
{
	if( in < 3 )
	{
		ss << in;
		string tmp;
		ss >> tmp;
		ss.clear();
		return tmp;
	}
	else
	{
		f1( in / 3 );
		ss << in % 3;
	}
}

void turnlight( int k, char s[] )
{
	if( s[ k ] == 'R' )
	{
		s[ k ] = 'G';
	}
	else if( s[ k ] == 'G' )
	{
		s[ k ] = 'B';
	}
	else if( s[ k ] == 'B' )
	{
		s[ k ] = 'R';
		if( k - 1 >= 0 )
		{
			turnlight( k - 1, s );
		}
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
		char s[ m ];
		memset( s, 'R', m );
		int64_t tmp = pow( 3, m );
		n %= tmp;


		string s = f1( n );
		for( int j = m; j != 0; j-- )
		{
			if( j > s.size() || s.at( j ) == '0' )
            {
                cout << 'R';
            }
            else
            {
                if( s.at( j ) == '1' )
                {
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
