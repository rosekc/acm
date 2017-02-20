//Program K
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	vector< string > a;
	vector< int > b;
	string t;
	int n;

	cin >> n;

	while( n != 0 )
	{

		int tp;
		int tMax = 0;

		cin >> t;

		a.push_back( t );
		b.push_back( 1 );

		for( int i = 2; i <= n; i++ )
		{
		    bool flag = 0;

			cin >> t;

			for( int j = 0; j < a.size(); j++ )
			{
				if( a.at( j ) == t )
				{
					b.at( j )++;
					flag = 1;
					break;
				}
			}

			if( flag == 0 )
			{
				a.push_back( t );
				b.push_back( 1 );
			}
		}

		for( int i = 0; i < a.size(); i++ )
		{
			if( tMax < b.at( i ) )
			{
				tMax = b.at( i );
				tp = i;
			}
		}

		cout << a.at( tp ) << endl;

		a.clear();
		b.clear();

		cin >> n;
	}


}
