#include <stdio.h>
#include <algorithm>
#include <string.h>

char in[ 110005 ];
char re[ 220100 ];
int p[ 220100 ];

int main()
{
	while ( scanf( "%s", in ) != EOF )
	{


		re[ 0 ] = '$';

		int insize = strlen( in );
		int maxp = 0;

		memset( p, 0, sizeof( p ) );

		//printf( "%d\n", insize );



		for( int i = 1; i <= 2 * insize + 2; i++ )
		{
			if( i % 2 == 1 )
			{
				re[ i ] = '#';
			}
			//else if( i == 2 * insize + 2 )
			//{
			//    re[ i ] = '$';
			//}
			else
			{
				re[ i ] = in[ i / 2 - 1 ];
			}
		}

		//printf( "%s\n", re );

		p[ 0 ] = 1;

		int maxlen = 0;
		int id = 0;

		for( int i = 1; re[ i ] != '\0'; i++ )
		{
			if( maxlen > i )
			{
				p[ i ] = ( p[ 2 * id - i ] < maxlen - i ? p[ 2 * id - i ] : maxlen - i );
			}
			else
            {
                p[ i ] = 1;
            }
			while( re[ i + p[ i ] ] == re[ i - p[ i ] ] )
			{
				p[ i ]++;
			}
			if( i + p[ i ] > maxlen )
			{
				maxlen = i + p[ i ];
				id = i;
			}
			if( p[ i ] > maxp )
            {
                maxp = p[ i ];
            }
		}
/*
		for( int i = 0; i < 2 * insize + 2; i++ )
		{
		    //printf( "%d ", p[ i ] );
			if( p[ i ] > maxp )
			{
				maxp = p[ i ];
			}
		}*/


		printf( "%d\n", maxp - 1 );
	}
}
