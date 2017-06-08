#include <cstdio>

struct time
{
	int st;
	int et;
	bool status;
};


time pro[ 405 ];

int main()
{
	int n;
	int t1, t2;
	int con;
	int t;
	int casec;

	scanf( "%d", &t );

	for ( int j = 1; j <= t; j++ )
	{
	    scanf( "%d", &n );

	    if( n == 0 )
        {
            printf( "0\n" );
            continue;
        }

		con = 0;
		casec = n;
		for ( int i = 1; i <= n; i++ )
		{
			scanf( "%d%d", &t1, &t2 );
			if( t1 < t2 )
            {
                pro[ i ] = { t1, t2, 0 };
            }
			else
            {
                pro[ i ] = { t2, t1, 0 };
            }
		}

		for ( int i = 0;; )
		{
			int mint = 10000;
			int flag = 0;
			int ind;
			for ( int j = 1; j <= n; j++ )
			{
				if ( pro[ j ].status == 0 && pro[ j ].st > i && pro[ j ].st - i < mint )
				{
					mint = pro[ j ].st - i;
					ind = j;
					flag = 1;
				}
			}
			if ( flag == 1 )
			{
				//printf( "%d\t%d\n", i, pro[ ind ].et );
                pro[ ind ].status = 1;
				i = pro[ ind ].et;
				if( i % 2 == 1 )
                    i++;
				casec--;
				if( casec == 0 )
                {
                    con++;
                    break;
                }
			}
			else
			{
			    con++;
			    i = 0;
			}
		}
		printf( "%d\n", con * 10 );
	}
}
