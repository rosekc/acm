#include <iostream>
#include <algorithm>
using namespace std;

const int tmax = 25;
const int wi[ 2 ] = { 1, -1 };
int lab[ tmax ];
int vis[ tmax ];
int aim;

int n;

bool dfs( int i, int sum, int con )
{
    vis[ i ] = 1;
    if( con == 3 ) return 1;

    //cout << sum << " " << aim << "\n";

    if( sum == aim )
    {
        int tmp = 0;
        while( vis[ tmp ] == 1 ) tmp++;
        if( dfs( tmp, lab[ tmp ], con + 1 ) ) return 1;
        else
        {
            vis[ i ] = 0;
            return 0;
        }
    }

    for( int j = i + 1; j < n; j++ )
    {
        if( sum + lab[ j ] > aim || vis[ j ] == 1 ) break;
        while(  j < n && lab[ j ] == 1 ) j++;
        if( j >= n ) break;
        if( dfs( j, sum + lab[ j ], con ) ) return 1;
    }
    vis[ i ] = 0;
    return 0;
}

int main()
{
	int t;
	int sr, sc;
	int er, ec;
	cin >> t;

	while ( t-- )
	{
		int sum = 0;
		cin >> n;

		//cout << n << endl;

		for ( int i = 0; i < n; i++ )
		{
			cin >> lab[ i ];
			vis[ i ] = 0;
			sum += lab[ i ];
		}

		sort( lab, lab + n );


		if ( sum % 4 != 0 || sum / 4 < lab[ n - 1 ] )
		{
			cout << "no\n";
			continue;
		}

		aim = sum / 4;

		if( dfs( 0, lab[ 0 ], 0 ) ) cout << "yes\n";
		else cout << "no\n";;

		//cout << "2\n";
	}
}
