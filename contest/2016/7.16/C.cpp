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

struct Line
{
	Point s, e;
	Line() {}
	Line(Point _s, Point _e)
	{
		s = _s;
		e = _e;
	}

	pair<int, Point> operator &( const Line &b)const
	{
		Point res = s;
		if ( sgn(( s - e ) ^ ( b.s - b.e)) == 0)
		{
			if ( sgn(( s - b.e ) ^ (b.s - b.e)) == 0)
				return make_pair( 0, res );
			else return make_pair(1, res );
		}
		double t = ( ( s - b.s ) ^ (b.s - b.e)) / (( s - e) ^ (b.s - b.e ));
		//printf( "%lf %lf\n", res.x, res.y  );
		res.x += ( e.x - s.x ) * t;
		res.y += ( e.y - s.y ) * t;
		//printf( "%lf %.2lf\n", res.x, res.y  );
		return make_pair(2, res );
	}
};

double dist( Point a, Point b )
{
	return sqrt( (a - b) * ( a - b ) );
}

int main()
{
	int t;
	Line l1, l2;

	scanf("%d", &t );
	printf( "INTERSECTING LINES OUTPUT\n");

	while ( t-- )
	{
		scanf( "%lf%lf%lf%lf%lf%lf%lf%lf", &l1.s.x, &l1.s.y, &l1.e.x, &l1.e.y,
		       &l2.s.x, &l2.s.y, &l2.e.x, &l2.e.y );
		pair<int, Point> res = ( l1 & l2 );
		if ( res.first == 0 )
		{
			printf("LINE\n");
		}
		else if ( res.first == 1 )
		{
			printf( "NONE\n");
		}
		else if ( res.first == 2 )
		{
			printf( "POINT %.2lf %.2lf\n", res.second.x, res.second.y  );
		}
	}
	printf("END OF OUTPUT\n");
}

