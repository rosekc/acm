#include <iostream>
#include <string>
using namespace std;

void f1( string &in, int n )
{
	if ( n - 1 < 0 )
	{
		//cout << 1 << endl;
		in = '1' + in;
	}
	else
	{
		if ( in.at( n - 1 ) == '9' )
		{
			f1( in, n - 1 );
			//cout << n<<endl;
			in.at( n ) = '0';
		}
		else
		{
			in.at( n - 1 ) = char( int( in.at( n - 1 ) ) + 1 );
		}
	}
}

void f1_1( string &in, int n, string &a1 )
{
	if ( n == 0 )
	{
		f1( a1, a1.size() );
		in.at( 0 ) = '0';
	}
	else
	{
		if ( in.at( n - 1 ) == '9' )
		{
			f1_1( in, n - 1, a1 );
			//cout << 1 << endl;
			in.at( n - 1 ) = '0';
		}
		else
		{
			in.at( n - 1 ) = char( int( in.at( n - 1 ) ) + 1 );
		}
	}
}

string f2( string &a, string &b )
{
	string st;
	if ( a.size() < b.size() )
	{
		st = a;
		a = b;
		b = st;
	}

	string re;

	for ( int i = 1; i <= a.size(); i++ )
	{
		//cout << i << endl;
		if ( i > b.size() )
		{
			re = a.at( a.size() - i ) + re;
		}
		else
		{
			int tmp = int( a.at( a.size() - i ) ) + int ( b.at( b.size() - i ) ) - int( '0' );
			//cout << char(tmp) << endl;
			if ( tmp > char( '9' ) )
			{
				re = char( tmp - int( '9' ) + int( '0' ) - 1 ) + re;
				f1( a, a.size() - i );
			}
			else
			{
				re = char( tmp ) + re;
			}
		}
	}
	//cout << 2 << endl;
	return re;
}

string f2_1( string &a, string &b, string &a1 )
{
	string st;
	if ( a.size() < b.size() )
	{
		st = a;
		a = b;
		b = st;
	}

	string re;

	for ( int i = a.size() - 1; i >= 0; i-- )
	{
		if ( i >= b.size() )
		{
		    //cout << 1 << endl;
			re = a.at( i ) + re;
			//cout << 2 << endl;
		}
		else
		{
			int tmp = int( a.at(  i ) ) + int ( b.at( i ) ) - int( '0' );
			//cout << char(tmp) << endl;
			if ( tmp > char( '9' ) )
			{
				re = char( tmp - int( '9' ) + int( '0' ) - 1 ) + re;
				//cout << 1 << endl;
				f1_1( a, i, a1 );
				//cout << 2 << endl;
			}
			else
			{
				re = char( tmp ) + re;
			}
		}
	}
	return re;
}

int f3( string &in )
{
	for ( int i = 0; i < in.size(); i++ )
	{
		if ( in.at( i ) == '.' )
		{
			return i;
		}
	}
	return -1;
}

string f4( string &a, string &b, string &a1 )
{
	string in = f2_1( a, b, a1 );

	while ( in.size() >= 1 && in.at( in.size() - 1 ) == '0' )
	{
		in.erase( in.size() - 1, 1 );
	}

	return in;
}

string f4_1( string &a )
{
	while ( a.size() >= 1 && a.at( a.size() - 1 ) == '0' )
	{
		a.erase( a.size() - 1, 1 );
	}
	return a;
}

int main()
{
	string a, b;
	int n, i = 0;

	cin >> n;

	while ( ( n-- ) != 0 )
	{
        cin >> a >> b;
		if ( f3( a ) != -1 && f3(  b ) != -1 )
		{

			string a1( a, 0, f3( a ) );
			string a2( a, f3( a ) + 1, a.size() - ( f3( a ) + 1 ) );
			string b1( b, 0, f3( b ) );
			string b2( b, f3( b ) + 1, b.size() - ( f3( b ) + 1 ) );
			string c2 = f4( a2, b2, a1 );
			string c1 = f2( a1, b1 );
			cout << c1;
			if(  c1.empty() )
            {
               cout << 0;
            }
			if ( !( c2.empty() ) )
			{
				cout << "." << c2;
			}
		}
		else if( f3( a ) == -1 && f3(  b ) != -1 )
        {
			string b1( b, 0, f3( b ) );
			string b2( b, f3( b ) + 1, b.size() - ( f3( b ) + 1 ) );
			string c2 = f4_1( b2 );
			string c1 = f2( a, b1 );
			cout << c1;
			if ( !( c2.empty() ) )
			{
				cout << "." << c2;
			}
        }
        else if( f3( a ) != -1 && f3(  b ) == -1 )
        {
            string a1( a, 0, f3( a ) );
			string a2( a, f3( a ) + 1, a.size() - ( f3( a ) + 1 ) );
			string c2 = f4_1( a2 );
			string c1 = f2( a1, b );
			cout << c1;
			if ( !( c2.empty() ) )
			{
				cout << "." << c2;
			}
        }
        else
		{
		    cout << "Case " << ++i << ":\n";
			cout << a << " + " <<  b << " = " << f2( a, b ) << endl;
		}

		if( n == 0 ) cout << endl;
		//cout << re << endl;
	}
}
