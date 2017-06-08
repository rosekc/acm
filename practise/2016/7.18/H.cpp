#include <iostream>

using namespace std;

int table[ 9 ][ 9 ];


bool check( int r, int c, int i )
{
	//cout << r << " " << c << " " << i <<endl;
	for ( int j = 0; j < 9; j++ )
	{
		if ( table[ j ][ c ] == i || table[ r ][ j ] == i )
		{
			return 0;
		}
	}
	//cout << "12346587\n";
	int x1, x2, y1, y2;
	if ( r <= 2 )
	{
		x1 = 0;
		x2 = 2;
	}
	else if ( r <= 5 && r >= 3 )
	{
		x1 = 3;
		x2 = 5;
	}
	else if ( r >= 6 )
	{
		x1 = 6;
		x2 = 8;
	}
	if ( c <= 2 )
	{
		y1 = 0;
		y2 = 2;
	}
	else if ( c <= 5 && c >= 3 )
	{
		y1 = 3;
		y2 = 5;
	}
	else if ( c >= 6 )
	{
		y1 = 6;
		y2 = 8;
	}

	for ( int j = x1; j <= x2; j++ )
	{
		for ( int k = y1; k <= y2; k++ )
		{
			//cout << j << endl;
			if ( table[ j ][ k ] == i )
			{
				//cout << x2 << " " << y2 << endl;
				//cout << j <<" " << k << endl;
				return 0;
			}
		}
	}
	//cout << r << " " << c << " " << i <<endl;
	return 1;
}


bool dfs( int r, int c, int con )
{
	//cout << r << " " << c << endl;
	for ( int i = 1; i <= 9; i++ )
	{
	    bool flag = 0;
		if ( check( r, c, i ) )
		{
			table[ r ][ c ] = i;
			//cout << i << endl;
			if ( con == 0 )
			{
				return 1;
			}
			for ( int l = 0; l < 9; l++ )
			{
				for ( int j = 0; j < 9; j++ )
				{
					if ( table[ l ][ j ] == 0 )
					{
						if ( dfs( l, j, con - 1 ) ) return 1;
						else
                        {
                            flag = 1;
                            break;
                        }
					}
				}
				if( flag == 1 ) break;
			}
		}
	}
    table[ r ][ c ] = 0;
    return 0;
}

int main()
{
	int t;
	//int c = 1;

	cin >> t;

	while ( t-- )
	{
		int con = 0;
		for ( int i = 0; i < 9; i++ )
		{
			for ( int j = 0; j < 9; j++ )
			{
				char tmp;
				cin >> tmp;
				if ( tmp == '0' ) con++;

				table[ i ][ j ] = int( tmp - 48 );
			}
		}

		//cout << con << endl;


		for ( int l = 0; l < 9; l++ )
		{
			for ( int j = 0; j < 9; j++ )
			{
				if ( table[ l ][ j ] == 0 )
				{
					dfs( l, j, con - 1 );
					break;
				}
			}
		}

		//cout << "Case #" << c++ << ":\n";

		for ( int l = 0; l < 9; l++ )
		{
			for ( int j = 0; j < 9; j++ )
			{
				cout << table[ l ][ j ];
				//if( j < 3 ) cout << " ";
			}
			cout << "\n";
		}

	}
}

