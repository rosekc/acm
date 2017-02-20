#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

struct pr
{
	int order;
	int priority;
};

struct cmp
{
	bool operator()( int a, int b )
	{
		return a < b;
	}
};

int main()
{
	queue< pr > qu;
	priority_queue< int, vector< int >, cmp > pq;
	int t;
	int n;
	int d;
	int tmp;

	scanf( "%d", &t );

	for ( int i = 1; i <= t; i++ )
	{
		int con = 1;
		scanf( "%d%d", &n, &d );
		for ( int j = 0; j < n; j++ )
		{
			scanf( "%d", &tmp );
			pq.push( tmp );
			qu.push( { j, tmp } );
		}

		int flag = 0;

		while ( flag != 1 )
		{
			if ( qu.front().priority != pq.top() )
			{
				qu.push( qu.front() );
				qu.pop();
			}

			while ( qu.front().priority == pq.top() )
			{
				if ( qu.front().order == d )
				{
				    flag = 1;
					break;
				}
				qu.pop();
				pq.pop();
				con++;
			}
		}



		printf( "%d\n", con );

		while ( qu.empty() == 0 )
		{
			qu.pop();
		}

		while ( pq.empty() == 0 )
		{
			pq.pop();
		}

	}


}
