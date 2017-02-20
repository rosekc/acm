#include <cstdio>
#include <algorithm>

using namespace std;

struct interval
{
	int sp;
	int ep;
};

bool cmp( interval a, interval b )
{
    return a.ep < b.ep;
}

interval data[ 20000 ];
int w[ 20000 ];
int n;
int t1, t2;

int main()
{
	while ( scanf( "%d", &n ) != EOF )
	{
	    int ans = 2;

		for ( int i = 0; i < n; i++ )
		{
			scanf( "%d%d", &t1, &t2 );
			data[ i ].sp = t1;
			data[ i ].ep = t2;
		}

		sort( data, data + n, cmp );

		int leftind = data[ 0 ].ep - 1;
		int rightind = data[ 0 ].ep;

		for( int i = 1; i < n; i++ )
        {
            if( data[ i ].sp <= leftind && data[ i ].ep >= rightind )
            {
                continue;
            }
            else if( data[ i ].sp <= rightind && data[ i ].ep >= rightind )
            {
                ans++;
                leftind = rightind;
                rightind = data[ i ].ep;
            }
            else
            {
                leftind = data[ i ].ep - 1;
                rightind = data[ i ].ep;
                ans += 2;
            }
        }

		printf( "%d\n", ans );
	}
}
