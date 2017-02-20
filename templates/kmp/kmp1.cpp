//kmp
#include <iostream>
#include <vector>
#include <string>

using namespace std;
/*
void getnext( string in, int tnext[] )
{
	tnext[ 0 ] = 0;

	for ( int i = 2; i <= in.size(); i++ )
	{
		int nmax = 0;
		for ( int k = 1; k <= i; k++ )
		{
		    bool flag = 0;
			for ( int j = 1; j <= k; j++ )
			{
				if ( in.at( j - 1 ) != in.at( i - j ) )
				{
				    flag = 1;
					break;
				}
			}
			if ( nmax < k + 1 && flag == 0)
			{
				nmax = k + 1;
			}
		}
		tnext[ i - 1 ] = nmax;
	}
}*/

void getnext( string pattern, int next[] )
{
    unsigned int i, t;

    int length = pattern.size();

    i = 1;
    t = 0;
    next[1] = 0;

    while(i < length + 1)
    {
        while(t > 0 && pattern[i - 1] != pattern[t - 1])
        {
            t = next[t];
        }

        ++t;
        ++i;

        if(pattern[i - 1] == pattern[t - 1])
        {
            next[i] = next[t];
        }
        else
        {
            next[i] = t;
        }
    }

    while(t > 0 && pattern[i - 1] != pattern[t - 1])
    {
        t = next[t];
    }

    ++t;
    ++i;

    next[i] = t;
}

int kmp()
{
	string pattern = "abcabcacab";
	int pnext[ pattern.size() + 1 ]; //= { 0, 1, 1, 0, 1, 1, 0, 5, 0, 1 };
	getnext( pattern, pnext );
	string target = "babcbabcabcaabcabcabcacabc";

	for ( int i = 1; i < pattern.size() +1 ; i++ )
	{
		cout << pnext[ i ] << "  ";
	}

	cout << endl;

	for ( int j = 0; j <= target.size() - pattern.size(); )
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
		j += i + 1 - pnext[ i + 1 ];
	}
	return -1;
}

int main()
{
	cout << kmp();
}
