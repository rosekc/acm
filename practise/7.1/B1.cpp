#include <iostream>
#include <string>

using namespace std;

int pnext[ 10005 ];

void getnext( string &in, int p[] )
{
	p[ 0 ] = 0;

	int i = 0;
	int fj = 0;

	while ( i < in.size() - 1 )
	{
		while ( fj > 0 && in.at( i ) != in.at( fj - 1 ) )
		{
			fj = p[ fj - 1 ];
		}

		i++;
		fj++;

		if ( in.at( i ) == in.at( fj - 1 ) )
		{
			p[ i ] = p[ fj - 1 ];
		}
		else
		{
			p[ i ] = fj;
		}
	}

	while ( fj > 0 && in.at( i ) != in.at( fj - 1 ) )
	{
		fj = p[ fj - 1 ];
	}

	i++;
	fj++;

	p[ i ] = fj;

}

int kmp( string &pattern, string &target )
{
    //string pattern = "abcabcacab";
	// = { 0, 1, 1, 0, 1, 1, 0, 5, 0, 1 };
	getnext( pattern, pnext );

	//for( int i = 0; i<pattern.size(); i++)
    //{
    //    cout << pnext[ i ] << " ";
    //}
    //cout << endl;
	//string target = "babcbabcabcaabcabcabcacabc";

	int i = 0;
	int con = 0;

	while ( i <= target.size() - pattern.size() )
	{
		int j = 0;
		while ( j < pattern.size() && target.at( i + j ) == pattern.at( j ) )
		{
			j++;
		}
		if ( j == pattern.size() )
		{
			con++;
			j = 0;
		}
		i += j + 1 - pnext[ j ];
	}
	return con;
}

int main()
{
    int n;
    string p, t;

    cin >> n;

    for( int i = 1; i <= n; i++ )
    {
        cin >> p >> t;

        cout << kmp( p, t ) << endl;
    }
}
