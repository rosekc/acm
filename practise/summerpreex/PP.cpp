//Program P - A == B ?
#include <iostream>
#include <string>
using namespace std;

void f1( string &a )
{
	bool flag = 0;

	for( int i = 0; i < a.size(); i++ )
	{
		if( a[ i ] == '.' )
		{
			flag = 1;
		}
	}

	if( a[ 0 ] == '.' )
	{
		a.insert( 0, 1, '0' );
	}

	while( a[ 0 ] == '0' )
	{
		a.erase( 0, 1 );
	}

	if( flag == 1 )
	{
		while( a[ a.size() - 1 ] == '0' || a[ a.size() - 1 ] == '.' )
		{
			if ( a[ a.size() - 1 ] == '.' )
			{
			    a.erase( a.size() - 1, 1 );
				break;
			}
			else
            {
                a.erase( a.size() - 1, 1 );
            }
		}
	}
}

int main()
{
	string a, b;

	while( cin >> a >> b )
	{
		f1( a );
		f1( b );

		if(  a  == b  )
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
}
