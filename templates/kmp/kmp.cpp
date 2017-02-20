//kmp
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void getnext( string in, int tnext[] )
{
	tnext[ 0 ] = 0;

	for ( int i = 1; i < in.size(); i++ )
	{
		int nmax = -1;
		for ( int k = 0; k < i; k++ )
		{
			for ( int j = 0; j < k; j++ )
			{
				if ( in.at( j ) == in.at( i - k + j ) )
				{
					if ( nmax < j )
					{
						nmax = j;
					}
				}
			}
		}
		tnext[ i ] = nmax;
	}
}

int kmp()
{
	string pattern = "abcabcacab";
	int pnext[ pattern.size() ]; //= { 0, 1, 1, 0, 1, 1, 0, 5, 0, 1 };
	getnext( pattern, pnext );
	string target = "babcbabcabcaabcabcabcacabc";

	for ( int i = 1; i < pattern.size() + 1 ; i++ )
	{
		cout << pnext[ i ] << "  ";
	}

	cout << endl;

	for ( int j = 0; j < target.size() - pattern.size(); )
	{
		int i = 0;
		while ( pattern.at( i ) == target.at( j + i ) )
		{
			i++;
			if ( i == pattern.size() )
			{
				return j + 1;
			}
		}
		j += i + 1 - pnext[ i ];
	}
	return -1;
}

int main()
{
	cout << kmp();
}
