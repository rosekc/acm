//Program I
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	char c;
	bool flag = 0;

	while( 1 )
	{
	    cin >> c;

        if( c == '@' )
            break;

        if( flag == 0 )
            flag = 1;
        else
            cout << endl;

        cin >> n;

		for( int i = 1; i < n; i++ )
		{
			for( int j = 1; j <= n - i; j++ )
			{
				cout << " ";
			}

			cout << c;
			for( int j = 1; j <= 2 * i - 3 ; j++ )
			{
				cout << " ";
			}
			if( i != 1 )
			{
				cout << c;
			}
			cout << endl;
		}

		for( int i = 1; i <= 2 * n - 1; i++ )
		{
			cout << c;
		}

		cout << endl;
	}
}
