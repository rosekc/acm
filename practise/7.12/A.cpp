#include <cstdio>
#include <cmath>

using namespace std;

const double eps = 1e-8;
const double PI = acos( -1.0 );
int sgn( double x )
{
    if( fabs( x ) < eps ) return 0;
    if( x < 0 ) return -1;
    else return 1;
}

struct Point
{
    double x, y;
    Point(){}
    Point( double _x, double _y )
    {
        x = _x; y =  _y;
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

double CalcArea( Point p[], int n )
{
    double res = 0;
    for( int i = 0; i < n; i++ )
        res += ( p[ i ] ^ p[ ( i + 1 ) % n ] ) / 2 ;
    return fabs( res );
}

Point p[ 105 ];

int main()
{
    int n;

    while ( scanf( "%d", &n ) != EOF && n != 0 )
    {
        for( int i = 0; i < n; i++ )
        {
            scanf( "%lf%lf", &p[ i ].x, &p[ i ].y );
        }
        printf( "%.1lf\n", CalcArea( p, n ) );
    }
}
