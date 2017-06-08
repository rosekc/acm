#include <iostream>
#include <vector>
#include <string>
using namespace std;

void f1( string &a )
{
	for( int i = 0; i < a.size(); i++ )
	{
		if( a[ i ] == ' ' || a[ i ] == '\t' )
		{
			a.erase( i, 1 );
		}
	}
}

int main()
{
    vector< string > b;
	string a;

	while( 1 )
	{
	    getline( cin,a );
	    b.push_back( a );
		for( int i = 0; i < b.size(); i++ )
        {
            cout << b.at( i ) << " ";
            cout << ( b.at( i ).empty() ) << endl;
        }
	}
}
