#include <iostream>
#include <string>

using namespace std;

int main()
{
	int a;
	string b;


	while( cin >> a )
	{
		int vSize = 0;
		int max = 0;
		string c[ a ];
		int d[ a ] = { 0 };

		for( int i = 1; i <= a; i++ )
		{
			bool flag = 0;
			cin >> b;

			for( int j = 0; j < a; j++ )
			{
				if( c[ j ] == b )
				{
					d[ j ]++;
					flag = 1;
					break;
				}
			}

			if( flag == 0 )
			{
				c[ vSize ] = b;
				d[ vSize ]++;
				vSize++;
			}

		}

		for( int i = 0; i < vSize; i++ )
		{
			if( d[ i ] > max )
			{
				max = d[ i ];
			}
		}

		cout << c[ max ] << endl;
	}
}
