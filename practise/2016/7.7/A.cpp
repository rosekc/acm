#include <cstdio>
#include <algorithm>

using namespace std;

struct room1
{
	int jb;
	int cf;
	double rate;
};

bool cmp( room1 &a, room1 &b )
{
    return a.rate > b.rate;
}


room1 room[ 5010 ];

int main()
{
	int n, m;
	int t1, t2;
	double con;

	while ( scanf( "%d%d", &m, &n ) != EOF && n != -1 && m != -1 )
	{
		con = 0;
		for ( int i = 1; i <= n; i++ )
		{
			scanf( "%d%d", &t1, &t2 );
			room[ i ] = { t1, t2, double( t1 ) / double( t2 )};
		}

		sort( room + 1, room + n + 1, cmp );

		for ( int i = 1;; )
		{
			if( room[ i ].cf < m && i <= n )
            {
                m -= room[ i ].cf;
                con += room[ i ].jb;
                //printf( "%lf\t%d\n", con, room[ i ].cf );
                i++;
            }
            else if( m > 0 && i <= n )
            {
                double tmpr = ( double( m ) / double( room[ i ].cf ) );
                con += ( room[ i ].jb * tmpr );
                //printf( "%.3f\t%d\n", tmpr, m );
                break;
            }
            else
            {
                break;
            }
		}
		printf( "%.3lf\n", con );
	}
}
