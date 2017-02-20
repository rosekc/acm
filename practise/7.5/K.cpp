#include <cstdio>
#include <algorithm>

using namespace std;

int u[ 2005 ];
int sex[ 2005 ];
int n;
int flag = 0;

void setr( int a )
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
}




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
    if( sex[ a ] == 0 && sex[ b ] == 0 )
    {
        sex[ a ] = 1;
        sex[ b ] = 2;
    }
    else if( sex[ a ] == 0 )
    {
        sex[ b ] == 1 ? sex[ a ] = 2 : sex[ a ] = 1;
    }
    else if( sex[ b ] == 0 )
    {
        sex[ a ] == 1 ? sex[ b ] = 2 : sex[ b ] = 1;
    }
    else if( sex[ a ] == sex[ b ] )
    {
        return 1;
    }


    int af = findr( u, a );
    int bf = findr( u, b );

    if( af != bf )
    {
        u[ af ] = bf;
    }
    return 0;
}


int main()
{
	int t1, t2;
	int m;
	int t;
	int c = 1;

	scanf( "%d", &m );


	for ( int i = 0; i < m; i++ )
	{
	    scanf( "%d%d", &n, &t );

	    flag = 0;


		for ( int i = 0; i <= n; i++ )
		{
		    sex[ i ] = 0;
			u[ i ] = i;
		}

		for ( int i = 0; i < t; i++ )
		{
			scanf( "%d%d", &t1, &t2 );

			//printf( "%d\n", n );

			if( connect( u, t1, t2 ) )
            {
                flag = 1;
            }


			/*
			for ( int i = 1; i <= n; i++ )
			{
			    while ( flag[ i ] == 0 )
			    {
			        i++;
			    }
			    int tmp = findr( u, i );
			    //printf( "%d\t%d\n", i, u[ i ] );
			}*/
		}
/*
		for ( int i = 1; i <= n; i++ )
		{
			setr( i );
		}

		sort( u, u + n + 1 );

		int tmp = u[ 1 ];
		int con = 1;
		int bcon = 1;

		//printf( "%d\t%d\n", 1, u[ 1 ] );

		for ( int i = 2; i <= n; i++ )
		{
			//printf( "%d\t%d\n", i, u[ i ] );
			if ( tmp == u[ i ] )
			{
				//printf( "%d\t%d\n", i, u[ i ] );
				con++;
			}
			else
			{
				tmp = u[ i ];
				con = 1;
			}
			if( con == 3 )
                break;
		}

		for ( int i = 1; i <= n; i++ )
		{
			printf( "%d\t%d\n", i, sex[ i ] );
		}
*/


		printf( "Scenario #%d:\n", c++ );

		if ( flag == 1 )
		{
			printf( "Suspicious bugs found!\n" );
		}
		else
        {
            printf( "No suspicious bugs found!\n" );
        }
	}
}
