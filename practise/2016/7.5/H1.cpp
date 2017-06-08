#include <cstdio>

int u[ 100020 ];
bool flag[ 100020 ];
bool flag2 = 0;
int n = 0;



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
	if ( u[ a ] == u[ b ] )
	{
		flag2 = 1;
	}
	if ( flag2 == 0 )
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
}


int main()
{
	int t1, t2;

	while ( 1 )
	{
		n = 0;
		int con = 0;
		flag2 = 0;
		for ( int i = 0; i <= 100019; i++ )
		{
			u[ i ] = i;
			flag[ i ] = 0;
		}




		while ( scanf( "%d%d", &t1, &t2 ) )
		{
			if ( t1 + t2 == 0 )
			{
				break;
			}
			if ( t1 + t2 == -2 )
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
		}
		if ( flag2 == 1 || con != 1  )
		{
		    if( con == 0 )
            {
                printf( "Yes\n" );
            }
            else
                printf( "No\n" );
		}
		else
		{
			printf( "Yes\n" );
		}
		//printf( "%d\n", con );
	}
}
