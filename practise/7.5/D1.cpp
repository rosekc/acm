#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int t;
	int tmp;
	vector < int > a;
	vector< int >::iterator iter;

	while ( scanf( "%d", &t ) != EOF && t != 0 )
	{
		scanf( "%d", &tmp );
		a.push_back( tmp );

		for( int i = 1; i < t; i++ )
		{
			scanf( "%d", &tmp );


			for( iter = a.begin(); ; iter++ )
			{
			    //cout <<*iter << " ";
			    if( iter - 1 == a.end() || iter == a.end() )
				{
					a.push_back( tmp );
					break;
				}
				if( tmp == *iter )
				{
				    //cout <<*iter << endl;
					a.erase( iter );
					//printf( "233\n" );
					break;
				}
			}
		}
		cout << a.at( 0 ) << endl;
		a.pop_back();
	}
}

