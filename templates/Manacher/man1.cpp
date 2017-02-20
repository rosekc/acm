//hdu 1856
#include <cstdio>
#include <algorithm>

using namespace std;

int u[ 40020 ];
bool flag[ 40020 ];
int n = 40021;

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

void connect( int u[], int a, int b )
{
    int af = findr( u, a );
    int bf = findr( u, b );

    if( af != bf )
        u[ af ] = bf;
}


int main()
{
	int t1, t2;
	int t;
	int c = 1;


	while ( scanf( "%d", &t ) != EOF )
	{
		for ( int i = 0; i <= n; i++ )
		{
			u[ i ] = i;
			flag[ i ] = 0;
		}

		n = 0;

		for ( int i = 0; i < t; i++ )
		{
			scanf( "%d%d", &t1, &t2 );
			if ( t1 > n )
			{
				n = t1;
			}
			if ( t2 > n )
			{
				n = t2;
			}


			//printf( "%d\n", n );

			connect( u, t1, t2 );
			flag[ t1 ] = 1;
			flag[ t2 ] = 1;

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
				if ( bcon < con )
				{
					bcon = con;
				}
				con = 1;
			}
		}

		if ( bcon < con )
		{
			bcon = con;
		}

		printf( "%d\n", bcon );
	}
}
