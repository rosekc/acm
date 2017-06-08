#include <stdio.h>
#include <cmath>

using namespace std;

const double eps = 1e-8;

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

Point getGravityPoint( Point p[], int n )
{
    Point c;
    double res;
    c.x = c.y = 0;
    for( int i = 0; i < n; i++ )
    {
        c.x += ( p[ i ].x + p[ ( i + 1 ) % n ].x ) * ( p[ i ] ^ p[ ( i + 1 ) % n ] );
        c.y += ( p[ i ].y + p[ ( i + 1 ) % n ].y ) * ( p[ i ] ^ p[ ( i + 1 ) % n ] );
        res += p[ i ] ^ p[ ( i + 1 ) % n ];
    }
    c.x /= ( 3 * res );
    c.y /= ( 3 * res );
    return c;
}

Point p[ 1000020 ];

int main()
{
    int t, n;

    scanf( "%d", &t );

    while ( t-- )
    {
        scanf( "%d", &n );

        for ( int i = 0; i < n; i++ )
        {
            scanf( "%lf%lf", &p[ i ].x, &p[ i ].y );
        }
        Point c = getGravityPoint( p, n );
        printf( "%.2lf %.2lf\n", c.x, c.y );
    }
}
