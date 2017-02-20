#include <iostream>
using namespace std;


int main()
{
	int n;

	cin >> n;

	while( n != 0 )
	{
	    int i = 1;
		for( ;; i *= 2 )
        {
            if( n % 2 != 0 )
            {
                break;
            }
            n /= 2;
        }
        cout << i << endl;
        cin >> n;
	}
}
