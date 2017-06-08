#include <iostream>
using namespace std;

int main()
{
	int m1, m2, r1, r2, r3;
	char order;

	while( cin >> m1 >> m2 )
	{
		r1 = 0;
		r2 = 0;
		r3 = 0;

		order = cin.get();
		order = cin.get();

		while( order != '\n' )
		{
			switch( order )
			{
			case 'A':
				r1 = m1;
				break;
			case 'B':
				r2 = m2;
				break;
			case 'C':
				m1 = r3;
				break;
			case 'D':
				m2 = r3;
				break;
			case 'E':
				r3 = r1 + r2;
				break;
			case 'F':
				r3 = r1 - r2;
				break;
			}

			order = cin.get();
		}
		cout << m1 << ',' << m2 << endl;
	}
}
