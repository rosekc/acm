#include <iostream>

using namespace std;

int table[ 4 ][ 4 ];


bool check( int r, int c, int i )
{
	for ( int j = 0; j < 4; j++ )
	{
		if ( table[ j ][ c ] == i || table[ r ][ j ] == i )
		{
			return 0;
		}
	}
	if ( r <= 1 && c <= 1 )
	{
		if ( table[ 0 ][ 0 ] == i || table[ 1 ][ 0 ] == i || table[ 0 ][ 1 ] == i || table[ 1 ][ 1 ] == i )
			return 0;
	}
	if ( r > 1 && c > 1 )
	{
		if ( table[ 2 ][ 2 ] == i || table[ 3 ][ 2 ] == i || table[ 2 ][ 3 ] == i || table[ 3 ][ 3 ] == i )
			return 0;
	}
	if ( r <= 1 && c > 1 )
	{
		if ( table[ 0 ][ 2 ] == i || table[ 1 ][ 2 ] == i || table[ 0 ][ 3 ] == i || table[ 1 ][ 3 ] == i )
			return 0;
	}
	if ( r > 1 && c <= 1 )
	{
		if ( table[ 2 ][ 0 ] == i || table[ 3 ][ 0 ] == i || table[ 2 ][ 1 ] == i || table[ 3 ][ 1 ] == i )
			return 0;
	}
	return 1;
}


bool dfs( int r, int c, int con )
{
	for ( int i = 1; i <= 4; i++ )
	{
	    int flag = 0;
		if ( check( r, c, i ) )
		{
			table[ r ][ c ] = i;
			if( con == 0 )
            {
                return 1;
            }
			for ( int l = 0; l < 4; l++ )
			{
				for ( int j = 0; j < 4; j++ )
				{
					if ( table[ l ][ j ] == 0 )
					{
						if( dfs( l, j, con - 1 ) ) return 1;
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
	int c = 1;

	cin >> t;

	while ( t-- )
	{
		int con = 0;
		for ( int i = 0; i < 4; i++ )
		{
			for ( int j = 0; j < 4; j++ )
			{
				char tmp;
				cin >> tmp;
				if ( tmp == '*' )
				{
					con++;
					table[ i ][ j ] = 0;
				}
				else
				{
					table[ i ][ j ] = int( tmp - 48 );
				}
			}
		}

		for ( int l = 0; l < 4; l++ )
		{
			for ( int j = 0; j < 4; j++ )
			{
				if ( table[ l ][ j ] == 0 )
				{
					dfs( l, j, con - 1 );
					break;
				}
			}
		}

		cout << "Case #" << c++ << ":\n";

		for ( int l = 0; l < 4; l++ )
		{
			for ( int j = 0; j < 4; j++ )
			{
				cout << table[ l ][ j ];
				//if( j < 3 ) cout << " ";
			}
			cout << "\n";
		}

	}
}
