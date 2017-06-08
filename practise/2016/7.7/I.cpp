#include <cstdio>

struct interval
{
	int sp;
	int ep;
	int weight;
};

interval data[ 20000 ];
int w[ 20000 ];
int n;
int t1, t2;
int maxt, mint;
int con1;
int con2;
int maxw;
int ind;

int main()
{
	while ( scanf( "%d", &n ) != EOF )
	{
		maxt = -25123;
		mint = 20000;
		con1 = 2 * n;
		con2 = 0;
		maxw = 0;
		ind;

		for ( int i = 0; i < n; i++ )
		{
			scanf( "%d%d", &t1, &t2 );
			for( int j = 0; j < i; j++ )
            {

            }
			if ( t1 < mint )
			{
				mint = t1;
			}
			if ( t2 > maxt )
			{
				maxt = t2;
			}
			data[ i ].sp = t1;
			data[ i ].ep = t2;
			data[ i ].weight = 2;
		}

		//printf( "%d%\t%d\n", mint, maxt);

		for ( int i = mint; i <= maxt; i++ )
		{
			w[ i ] = 0;
			for ( int j = 0; j < n; j++ )
			{
				if ( i >= data[ j ].sp && i <= data[ j ].ep )
				{
					w[ i ] += data[ j ].weight;
				}
			}
			if ( w[ i ] > maxw )
			{
				maxw = w[ i ];
				ind = i;
			}
			printf( "%d\t%d\n", i, w[ i ] );
		}

		//printf( "\n" );

		while ( 1 )
		{
			con2++;

			for ( int j = 0; j < n; j++ )
			{
				if ( data[ j ].weight == 0 )
				{
					continue;
				}
				if ( ind >= data[ j ].sp && ind <= data[ j ].ep )
				{
					data[ j ].weight--;
					con1--;
					for ( int i = data[ j ].sp; i <= data[ j ].ep; i++ )
					{
						if ( w[ i ] <= 0 )
						{
							continue;
						}
                        w[ i ]--;
					}
				}
			}

			w[ ind ] = -1;

			if ( con1 <= 0 )
			{
				break;
			}

			maxw = 0;

			for ( int i = mint; i <= maxt; i++ )
			{
				if ( w[ i ] > maxw && w[ i ] > 0 )
				{
					maxw = w[ i ];
					ind = i;
				}
				printf( "%d\t%d\n", i, w[ i ] );
			}
			//printf( "\n" );
		}

		printf( "%d\n", con2 );
	}
}
