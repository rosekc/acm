#include <cstdio>
#include <vector>

int u[ 100020 ];
bool flag[ 100020 ];
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

void connect( int u[], int a, int b )
{

	if ( flag[ a ] == 0 && flag[ b ] == 0 )
	{
		u[ a ] = b;
	}
	else if ( u[ a ] == a && u[ b ] == b )
	{
		if ( flag[ a ] == 1 && flag[ b ] == 0 )
		{
			u[ b ] = a;
		}
		else if ( flag[ a ] == 0 && flag[ b ] == 1 )
		{
			u[ a ] = b;
		}
		else
		{
			//u[ a ] = b;
			for ( int i = 1; i <= n; i++ )
			{
				if ( u[ i ] == a )
				{
					u[ i ] = b;
				}
			}
		}
	}
	else if ( u[ a ] != a && u[ b ] == b )
	{
		if ( flag[ b ] == 0 )
		{
			u[ b ] = findr( u, a );
		}
		else if ( flag[ b ] == 1 )
		{
			a = findr( u, a );
			for ( int i = 1; i <= n; i++ )
			{
				if ( u[ i ] == b )
				{
					u[ i ] = a;
				}
			}
		}
	}
	else if ( u[ a ] == a && u[ b ] != b )
	{
		if ( flag[ a ] == 0 )
		{
			u[ a ] = findr( u, b );
		}
		else if ( flag[ a ] == 1 )
		{
			b = findr( u, b );
			for ( int i = 1; i <= n; i++ )
			{
				if ( u[ i ] == a )
				{
					u[ i ] = b;
				}
			}
		}
	}
	else if ( u[ a ] != a && u[ b ] != b )
	{
		b = findr( u, b );
		a = findr( u, a );
		for ( int i = 1; i <= n; i++ )
		{
			if ( u[ i ] == b )
			{
				u[ i ] = a;
			}
		}
	}

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

		for( int i = 0; i < t; i++ )
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

		int rsize = 0;
		int re[ 50010 ][ 2 ];

		for ( int i = 0; i <= n; i++ )
		{
			while ( flag[ i ] == 0 )
			{
				i++;
			}
			if ( rsize == 0 )
			{
				re[ 0 ][ 0 ] = u[ i ];
				re[ 0 ][ 1 ] = 1;
				rsize++;
				continue;
			}
			for ( int j = 0; j < rsize; j++ )
			{
				if ( re[ j ][ 0 ] == u[ i ]  )
				{
					re[ j ][ 1 ]++;
					break;
				}
				if ( j == rsize - 1 )
				{
					re[ rsize ][ 0 ] = u[ i ];
					re[ rsize ][ 1 ] = 1;
					rsize++;
					break;
				}
			}
		}

		for ( int i = 1; i <= n; i++ )
		{
			while ( flag[ i ] == 0 )
			{
				i++;
			}
			//printf( "%d\t%d\n", i, u[ i ] );
		}

		int maxr = 0;
		for ( int j = 0; j < rsize; j++ )
		{
		    //printf( "%d\t%d\n", re[ j ][ 0 ], re[ j ][ 1 ] );
			if ( re[ j ][ 1 ] > maxr )
			{
                maxr = re[ j ][ 1 ];
			}
		}
		printf( "%d\n", maxr );
	}
}
