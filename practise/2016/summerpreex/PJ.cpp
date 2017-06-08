#include <iostream>
#include <string>
using namespace std;

int main()
{
	string input;

	cin >> input;

	while( input != "end" )
	{
		bool r1 = 0;
		int r2 = 0;
		int r3 = 0;

		for( int i = 0; i < input.size(); i++ )
		{
			if( input.at( i ) == 'a' ||
			        input.at( i ) == 'e' ||
			        input.at( i ) == 'i' ||
			        input.at( i ) == 'o' ||
			        input.at( i ) == 'u' )
			{
				r1 = 1;
				r2++;
				r3 = 0;
			}
			else
			{
				r2 = 0;
				r3 ++;
			}
			if( input.at( i ) != 'e' &&
                input.at( i ) != 'o' &&
                i < input.size() - 1 &&
                input.at( i ) == input.at( i + 1 ) )
			{
				r1 = 0;
				break;
			}
			if( r2 == 3 || r3 == 3 )
			{
				r1 = 0;
				break;
			}
		}

		if( r1 == 1 )
		{
			cout << "<" << input << "> is acceptable." << endl;
		}
		else
		{
			cout << "<" << input << "> is not acceptable." << endl;
		}


		cin >> input;
	}
}
