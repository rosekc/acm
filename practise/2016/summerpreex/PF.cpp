//Program F
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;



int main()
{
	int n, m;
	while( cin >> n >> m )
	{
		vector< int > data( n );
		vector< int > result( n * ( n + 1 ) / 2 );

		for( int i = 0; i < n; i++ )
		{
			cin >> data.at( i );
		}



		int r = 1;
		int c = 0;

		for( int i = 0; i < n * ( n + 1 ) / 2; i++ )
		{
			result.at( i ) = data.at( n - 1 - r ) + data.at( n - 1 - c );

			//if( i < m )
			//    cout << " ";
			//cout << endl;
			//cout << r << " " << c << endl;

			if( r < ( n - 1 ) )
			{
				r++;

			}
			else
			{
				c++;
				r = c + 1;
			}
			if( r == n )
			{
				break;
			}
		}

		//result = bubbleSort( result );
        sort( result.begin(), result.end() );

		for( int i = n * ( n + 1 ) / 2 - 1, j = 1; j <= m; j++ )
		{
			cout << result.at( i );
			if( j < m )
				cout << " ";
			i--;
			//cout << endl;
			//cout << r << " " << c << endl;
		}

		cout << endl;
		data.clear();
		result.clear();
	}


}
