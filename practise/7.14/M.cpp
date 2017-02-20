#include <iostream>
using namespace std;
const int lmax = 125;
int c1[lmax + 1], c2[lmax + 1];
int main()
{
	int n, i, j, k;
	for (i = 0; i <= lmax; i++)
	{
		c1[i] = 1;
		c2[i] = 0;
	}
	for (i = 2; i <= lmax; i++)
	{
		for (j = 0; j <= lmax; j++)
			for (k = 0; k + j <= lmax; k += i)
			{
				c2[j + k] += c1[j];
			}
		for (j = 0; j <= lmax; j++)
		{
			c1[j] = c2[j];
			c2[j] = 0;
		}
	}
	while (cin >> n)
	{
		cout << c1[n] << endl;
	}
	return 0;
}
