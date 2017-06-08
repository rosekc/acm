#include <stdio.h>

int u[ 100005 ];
bool flag[ 100005 ];
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
    //printf( "%d\n", n );
    if ( u[ b ] == u[ a ] )
	{
		flag2 = 1;
	}
	if ( ( u[ b ] == b && u[ a ] != a ) )//|| ( flag[ b ] == 1 && flag[ a ] == 0 ) )
	{
		u[ b ] = findr( u, a );
	}
	else if( u[ b ] == b && u[ a ] == a && flag[ b ] == 0 && flag[ a ] == 1 )
    {
        u[ b ] = a;
    }
    else if( u[ b ] != b && u[ a ] != a )
    {
        a = findr( u, a );
        b = findr( u, b );
        for( int i = 1; i <= n; i++ )
        {
            if( u[ i ] == b )
            {
                u[ i ] = a;
                //printf( "1\n" );
            }
            //printf( "%d\n", u[ i ] );
        }
    }
    else if( u[ b ] == b && u[ a ] == a && flag[ b ] == 1 && flag[ a ] == 1 )
    {
       // printf( "1\n" );
        for( int i = 1; i <= n; i++ )
        {
            if( u[ i ] == b )
            {
                u[ i ] = a;
                //printf( "1\n" );
            }
            //printf( "%d\n", u[ i ] );
        }
    }
	else
	{
		u[ findr( u, a ) ] = findr( u, b );
	}

	//printf( "%d\n%d\n", findr( u, a ), u[ 1 ] );
}

int main()
{
	int t1, t2;

	while ( 1 )
	{
		n = 0;
		int con = 0;
		flag2 = 0;
		for ( int i = 1; i <= 100005; i++ )
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
			printf( "%d\t%d\n", i, u[ i ] );
		}
		if ( flag2 == 1 || con != 1 )
		{
			printf( "No\n" );
		}
		else
		{
			printf( "Yes\n" );
		}
		//printf( "%d\n", con );
	}
}
