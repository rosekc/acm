//Program N - »Àº˚»À∞ÆA-B
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int m, n;

	cin >> m >> n;

	while( m + n != 0 )
	{
		vector< int > a( m );
		vector< int > s( m );
		vector< int > b( n );
		int con = 0;

		for( int i = 0; i < m; i++ )
		{
			cin >> a.at( i );
		}

		for( int i = 0; i < n; i++ )
		{
			cin >> b.at( i );
		}

		for( int i = 0; i < m; i++ )
		{
			for( int j = 0; j < n; j++ )
			{
				if( b.at( j ) == a.at( i ) )
				{
					s.at( i ) = 1;
					con++;
				}
			}
		}

		con = m - con;

		if( con == 0 )
		{
			cout << "NULL";
		}
		else
		{
			for( int j = 1; j <= con; j++ )
			{
				int aMin = 2147483647;
				int ti;
				for( int i = 0; i < m; i++ )
				{
					if( s.at( i ) == 0 && a.at( i ) < aMin )
					{
						aMin = a.at( i );
						ti = i;
					}
				}
				s[ ti ] = 1;
				cout << aMin << " ";
			}
		}

		cout << endl;

		cin >> m >> n;

	}
}
