#include <iostream>

using namespace std;

int main()
{
	int in;
	int sum = 0;
	while(cin>>in)
	{

		for( int i = 1; i <= in; i++ )
		{
			sum += i;
		}
		cout << sum << endl << endl;
		sum = 0;
	}
}

