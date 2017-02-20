#include <cstdio>

int u[ 100020 ];
int indegree[ 100020 ];
bool flag[ 100020 ];
bool flag2 = 0;
int n = 100020;



int findr( int u[], int a )
{
	int tmp = u[ a ];
	//printf( "%d\n", tmp );
	while ( u[ tmp ] != tmp )
	{
		tmp = u[ tmp ];
	}
	u[ a ] = tmp;
	//flag[ a ] = 1;
	//printf( "%d\n", tmp );
	return tmp;
}

bool connect( int u[], int a, int b )
{
	int af = findr( u, a );
	int bf = findr( u, b );

	if ( af != bf )
	{
	    u[ af ] = bf;
	    return 0;
	}
    else
    {
        return 1;
    }
}


int main()
{
	int t1, t2;
	int c = 1;
	int con;

	while ( 1 )
	{
		flag2 = 0;
		for ( int i = 0; i <= n; i++ )
		{
			u[ i ] = i;
			indegree[ i ] = 0;
			flag[ i ] = 0;
		}

		con = 0;
		n = 0;

		while ( scanf( "%d%d", &t1, &t2 ) )
		{
			if ( t1 + t2 == 0 )
			{
				break;
			}
			if ( t1 < 0 && t2 < 0 )
			{
				return 0;
			}

			if ( t1 > n )
			{
				n = t1;
			}
			if ( t2 > n )
			{
				n = t2;
			}

			if ( connect( u, t1, t2 ) )
				flag2 = 1;
			flag[ t1 ] = 1;
			flag[ t2 ] = 1;
			indegree[ t2 ]++;
		}



		if ( flag2 == 1 )
		{
			printf( "Case %d is not a tree.\n", c++ );
		}
		else
		{
			for ( int i = 1; i <= n; i++ )
			{
				while ( flag[ i ] == 0 )
				{
					i++;
				}
				if ( u[ i ] == i )
				{
					con++;
					//printf( "%d\t%d\n", i, u[ i ] );
				}
				//printf( "%d\t%d\n", i, u[ i ] );
				if( indegree[ i ] > 1 )
                {
                    con = 999;
                    break;
                }
			}
			if ( con == 0 || con == 1 )
			{
				printf( "Case %d is a tree.\n", c++ );
			}
			else
				printf( "Case %d is not a tree.\n", c++ );
		}

		//printf( "%d\n", con );
	}
}
