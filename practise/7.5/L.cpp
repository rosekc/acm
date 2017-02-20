#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct cn
{
	string oldn;
	string newn;
};

int main()
{
	queue< cn > qu;
	int n;
	string t1, t2;
	cn data[ 1001 ];
	int con = 1;

	cin >> n;
	for( int i = 1; i <= n; i++ )
	{
		cin >> t1 >> t2;
		qu.push( { t1, t2 } );
	}

	data[ 0 ] = qu.front();
	qu.pop();

	while( qu.empty() != 1 )
	{
		for( int i = 0; i < con; i++ )
		{
			if( data[ i ].newn == qu.front().oldn )
			{
				data[ i ].newn = qu.front().newn;
				qu.pop();
				break;
			}
			if( i == con - 1 )
			{
				data[ con ] = qu.front();
				qu.pop();
				con++;
				break;
			}
		}
	}

	cout << con << endl;
	for( int i = 0; i < con; i++ )
	{
		cout << data[ i ].oldn << " " << data[ i ].newn << endl;
	}
}
