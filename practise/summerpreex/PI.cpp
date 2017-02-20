//Problem I Online Judge
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void f1( string &a )
{

	for( int i = 0; i < a.size(); i++ )
	{
		while( a[ i ] == ' ' || a[ i ] == '\t' )
		{
			a.erase( i, 1 );
		}
	}

}

int main()
{
	int n;

	cin >> n;

	for( int i = 1; i <= n; i++ )
	{
		string t;
		string rt;
		string st;
		bool flag = 0;
		vector< string > rightAns;
		vector< string > submitData;

		while( t != "START" )
		{
			cin >> t;
		}

		while( 1 )
		{
			getline( cin, t );

			if( t == "END" )
				break;

			rightAns.push_back( t );
		}

		while( t != "START" )
		{
			cin >> t;
		}

		while( 1 )
		{
			getline( cin, t );

			if( t == "END" )
				break;

			submitData.push_back( t );
		}

		if( rightAns.size() != submitData.size() )
		{
			flag = 1;
		}
		else
		{
			for( int j = 0; j < rightAns.size(); j++ )
			{
				if( rightAns.at( j ) != submitData.at( j ) )
				{
					flag = 1;
					break;
				}
			}

		}

		if( flag == 0 )
		{
			cout << "Accepted" << endl;
		}
		else
		{


			for( int j = 0; j < rightAns.size(); j++ )
			{
				rt += rightAns.at( j );
			}

			for( int j = 0; j < submitData.size(); j++ )
			{
				st += submitData.at( j );
			}

			f1( rt );
			f1( st );

			if( rt != st )
			{
				cout << "Wrong Answer" << endl;
			}
			else
			{
				cout << "Presentation Error" << endl;
			}
		}

	}
}
