#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

vector<string> f2( string &a )
{
	vector< string > tmp( 1 );
	int con = 0;

	for( int i = 0; i < a.size(); i++ )
	{
		if( a[ i ] == '5' )
		{
			a[ i ] = ' ';
			con++;
			tmp.push_back( "" );
		}
		else
		{
			tmp.at( con ).push_back( a[ i ] );
		}
	}

	return tmp;

}

void bubbleSort( vector< int > in )
{
	int key;
	int flag;



	for ( int c = 0; c < in.size(); c++ )
	{
		flag = 0;

		for ( int i = 1; i < in.size() - c; i++ )
		{
			if ( in[ i - 1 ] > in[ i ] )
			{
				key = in[ i - 1 ];
				in[ i - 1 ] = in[ i ];
				in[ i ] = key;

				flag = 1;
			}
		}

		if ( flag == 0 )
		{
			break;
		}
	}
	for( int i = 0; i < in.size(); i++ )
	{
		cout << in.at( i );
		if( i < in.size() - 1 )
            cout << " ";
	}
	cout << endl;
}

int main()
{
	string n;
	vector< string >t;
	vector< int > t2;
	stringstream ss;

	while( cin >> n )
	{

		t = f2( n );

		for( int i = 0; i < t.size(); i++ )
		{
			//cout << t.at( i ) << " ";
			if( t.at( i ) != "" )
			{
				int tmp;
				ss << t.at( i );
				ss >> tmp;
				t2.push_back( tmp );
				ss.clear();
				//cout << t2.at( i ) << " ";
			}

		}

		bubbleSort( t2 );

		//for( int i = 0; i < t2.size(); i++ )
		//{
		//	cout << t2.at( i ) << " ";
		//}
		t2.clear();
	}
}
