//Program O - »Àº˚»À∞ÆA^B
#include <iostream>
using namespace std;

int main()
{
	int a, b, n;

	cin >> a >> b;

	while( a + b != 0 )
    {
        n = a;
        for( ; b > 1; b-- )
        {
            n *= a;
            n %= 1000;
        }

        cout << n << endl;

        cin >> a >> b;
    }
}
