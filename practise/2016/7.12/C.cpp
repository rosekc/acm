#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

struct Point
{
	double x, y;
	Point() {}
	Point( double _x, double _y )
	{
		x = _x;
		y =  _y;
	}
	Point operator - ( const Point &b ) const
	{
		return Point(x - b.x, y - b.y );
	}
	double operator ^ ( const Point &b ) const
	{
		return x * b.y - y * b.x;
	}
	double operator * ( const Point &b ) const
	{
		return x * b.x + y * b.y;
	}
};

double dist(Point a, Point b)
{
	return sqrt((a - b) * (a - b));
}

const double eps = 1e-8;
const int MAXN = 1050;
Point list[MAXN];
int Stack[MAXN], top;
const double PI = acos( -1.0 );

int sgn( double x )
{
	if ( fabs( x ) < eps ) return 0;
	if ( x < 0 ) return -1;
	else return 1;
}


bool _cmp (Point p1, Point p2)
{
	double tmp = (p1 - list[0]) ^ (p2 - list[0]);
	if (sgn(tmp) > 0)return true;
	else if (sgn(tmp) == 0 && sgn(dist(p1, list[0]) - dist(p2, list[0])) <= 0)
		return true;
	else return false;
}
void Graham(int n)
{
	Point p0;
	int k = 0;
	p0 = list[0];

	for (int i = 1; i < n; i++)
	{
		if ( (p0.y > list[i].y) || (p0.y == list[i].y && p0.x > list[i].x) )
		{
			p0 = list[i];
			k = i;
		}
	}
	swap(list[k], list[0]);
	sort(list + 1, list + n, _cmp);
	if (n == 1)
	{
		top = 1;
		Stack[0] = 0;
		return;
	}
	if (n == 2)
	{
		top = 2;
		Stack[0] = 0;
		Stack[1] = 1;
		return;
	}
	Stack[0] = 0;
	Stack[1] = 1;
	top = 2;
	for (int i = 2; i < n; i++)
	{
		while (top > 1 &&
		        sgn((list[Stack[top - 1]] - list[Stack[top - 2]]) ^ (list[i] - list[Stack[top - 2]])) <= 0)
			top--;
		Stack[top++] = i;
	}
}

double getc( int r )
{
	double ans = PI * 2 * r;
	//if( top == 1 ) return 0;
	//if( top == 2 ) return dist( list[ 0 ], list[ Stack[ 1 ] ] );
	for ( int i = 0; i < top; i++ )
	{
		ans += dist( list[ Stack[ i ] ], list[ Stack[ ( i + 1 ) % top ] ] );
	}
	return ans;
}

int main()
{
	int n, l, t;

	scanf( "%d", &t );

	while ( t-- )
	{
	    scanf( "%d%d", &n, &l );
	    for ( int i = 0; i < n; i++ )
		{
			scanf( "%lf%lf", &list[ i ].x, &list[ i ].y );
		}

		Graham( n );

		printf( "%.0lf\n", getc( l ) );
		if( t != 0 ) printf( "\n" );
	}
}
