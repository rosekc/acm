#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const double eps = 1e-8;
const double PI = acos( -1.0 );
int sgn(double x)
{
	if (fabs( x) < eps ) return 0;
	if ( x < 0 ) return -1;
	else return 1;
}
struct Point
{
	double x, y;
	Point() {}
	Point(double _x, double _y )
	{
		x = _x;
		y = _y;
	}
	Point operator - ( const Point &b)const
	{
		return Point( x - b.x, y - b.y);
	}
	double operator ^ ( const Point &b )const
	{
		return x * b.y - y * b.x;
	}
	double operator * ( const Point &b )const
	{
		return x * b.x + y * b.y;
	}
};

double dist( Point a, Point b )
{
	return sqrt( (a - b) * ( a - b ) );
}

const int MAXN = 20020;
Point list[MAXN];
int Stack[ MAXN ], top;

bool _cmp( Point p1, Point p2 )
{
	double tmp = ( p1 - list[ 0 ] ) ^ ( p2 - list[ 0 ] );
	if (  sgn(tmp) > 0 ) return 1;
	else if (sgn(tmp) == 0 && sgn( dist( p1, list[ 0 ]) - dist(p2, list[ 0 ])) <= 0)
		return 1;
	else return 0;
}

void Graham(int n )
{
	Point p0;
	int k = 0;
	p0 = list[ 0 ];

	for ( int i = 1; i < n; i++ )
	{
		if ( (p0.y > list[i].y) || (p0.y == list[ i ].y && p0.x > list[ i ].x))
		{
			p0 = list[i];
			k = i;
		}
	}
	swap( list[k], list[ 0 ]);
	sort(list + 1, list + n, _cmp);
	if ( n == 1 )
	{
		top = 1;
		Stack[0] = 0;
		return;
	}
	if ( n == 2 )
	{
		top = 2;
		Stack[ 0 ] = 0;
		Stack[ 1 ] = 1;
		return;
	}
	Stack[ 0 ] = 0;
	Stack[ 1 ] = 1;
	top = 2;

	for ( int i = 2; i < n; i++ )
	{
		while (top > 1 &&
		        sgn((list[ Stack[ top - 1] ] - list[Stack[ top - 2]]) ^ (list[ i ] - list[ Stack[ top - 2]])) <= 0 )
		{
			top--;
		}
		Stack[ top++ ] = i;
	}
}

double CalcArea(Point p[], int n )
{
	double res = 0;
	for ( int i = 0; i < n; i++ )
	{
		res += ( p[ Stack[ i ] ] ^ p[ Stack[ ( i  + 1 ) % n ] ] ) / 2;
	}
	return res;
}

int main()
{
	int n;

	while ( scanf( "%d", &n ) != EOF )
	{
		for ( int i = 0; i < n; i++ )
		{
			scanf( "%lf%lf", &list[ i ].x, &list[ i ].y );
		}

		Graham( n );

		printf( "%.0lf\n", floor( ( CalcArea( list, top ) ) / 50.0 ) );
	}
}

