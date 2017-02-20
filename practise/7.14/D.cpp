#include <cstdio>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

int gcd(int a, int b)
{
	while(b)
	{
		int tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}

int main()
{
	string in1, in2;
	unsigned long long a1, a2, b1, b2;
	unsigned long long out1, out2;
	stringstream ss;
	int t;
	int tmp;
	cin >> t;

	while ( t-- )
	{
		cin >> in1 >> in2;

		for( int i = 0; i < in1.size(); i++ )
		{
			if( in1.at( i ) != '/' ) ss << in1.at( i );
			else
			{
				ss >> a1;
				ss.clear();
			}
		}
		ss >> a2;
		ss.clear();

		for( int i = 0; i < in2.size(); i++ )
		{
			if( in2.at( i ) != '/' ) ss << in2.at( i );
			else
			{
				ss >> b1;
				ss.clear();
			}
		}
		ss >> b2;
		ss.clear();

		a1 /= gcd( a1, b2 );
		b2 /= gcd( a1, b2 );
		b1 /= gcd( b1, a2 );
		a2 /= gcd( b1, a2 );

		a1 *= b2;
		b1 *= a2;

		tmp = gcd( a1, b1 );

		cout << a1 << " " << b1 << endl;

		a1 /= tmp;
		b1 /= tmp;

		cout << a1 << " " << b1 << endl;
		cout << a2 << " " << b2 << endl;

		out1 = a1 * b1;
		out2 = a2 * a2;

		cout << out1 << " " << out2 << endl;

		out1 /= gcd( out1, out2 );
		out2 /= gcd( out1, out2 );

		if( out2 == 1 )
            cout << out1 << endl;
        else
            cout << out1 << '/' << out2 << endl;
	}
}
