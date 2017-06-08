//F - Machine
#include <iostream>
#include <memory.h>

using namespace std;

void turnlight( int k, char s[] )
{
	if( s[ k ] == 'R' )
	{
		s[ k ] = 'G';
	}
	else if( s[ k ] == 'G' )
	{
		s[ k ] = 'B';
	}
	else if( s[ k ] == 'B' )
	{
		s[ k ] = 'R';
		if( k - 1 >= 0 )
        {
            turnlight( k - 1, s );
        }
    }
}

int main()
{
	int t, m;
	int64_t n;

	cin >> t;

	for( int i = 1; i <= t; i++ )
	{
		cin >> m >> n;
		char s[ m ];
		memset( s, 'R', m );

		for( int j = 1; j <= n; j++ )
		{
		    turnlight( m - 1, s );
		}
		for( int j = 0; j < m; j++ )
        {
            cout << s[ j ];
        }
        cout << endl;
	}

}
