#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;

int pnext[ 10005 ];

void getnext( char in[], int p[] )
{
	p[ 0 ] = 0;

	int insize = strlen( in );

	int i = 0;
	int fj = 0;

	while ( i < insize - 1 )
	{
		while ( fj > 0 && in[ i ] != in[ fj - 1 ] )
		{
			fj = p[ fj - 1 ];
		}

		i++;
		fj++;

		if ( in[ i ] == in[ fj - 1 ] )
		{
			p[ i ] = p[ fj - 1 ];
		}
		else
		{
			p[ i ] = fj;
		}
	}

	while ( fj > 0 && in[ i ] != in[ fj - 1 ] )
	{
		fj = p[ fj - 1 ];
	}

	i++;
	fj++;

	p[ i ] = fj;

}

int kmp( char pattern[], char target[] )
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
	int tsize = strlen( target );
	int psize = strlen( pattern );

	while ( i <= tsize - psize )
	{
		int j = 0;
		while ( j < psize && target[ i + j ] == pattern[ j ] )
		{
			j++;
		}
		if ( j == psize )
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
    char p[ 10005 ], t[ 1000005 ];

    scanf( "%d", &n );

    for( int i = 1; i <= n; i++ )
    {
        scanf( "%s%s", &p, &t );
        printf( "%d\n", kmp( p, t ) );
    }
}
