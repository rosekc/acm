//H - Train Problem I
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	int n;
	string a, b;

	while( cin >> n >> a >> b )
	{
		bool flag = 0;
		stack< int > sta;
		string s;
		int con = 0;
		for( int i = 0; i < n; i++ )
		{
		    //cout << i<< endl;
		    s += '0';
            sta.push( a.at( i ) );


			while( !sta.empty() && sta.top() == b.at( con ) )
			{
			    //cout << 1<< endl;
				s += '1';
				sta.pop();
				con++;
				if( con == n )
                {
                    break;
                }
                //cout << b.size() << endl;

			}
			 //cout << 1<< endl;
		}

		if( sta.empty() )
		{
			cout << "Yes." << endl;
			for( int i = 0; i < 2 * n; i++ )
			{
				if( s.at( i ) == '0' )
                {
                    cout << "in" << endl;
                }
                else
                {
                    cout << "out" << endl;
                }
			}
		}
		else
        {
            cout << "No." << endl;
        }
        cout << "FINISH" << endl;

        s.clear();
	}
}
