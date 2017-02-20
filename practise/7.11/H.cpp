#include <cstdio>
#include <cmath>

using namespace std;

int a[ 20 ];
int m[ 20 ];

long long extend_gcd(long long a, long long b, long long &x, long long  &y)
{
	if (a == 0 && b == 0)return -1;
	if (b == 0 )
	{
		x = 1;
		y = 0;
		return a;
	}
	long long d = extend_gcd(b, a % b, y, x);
	y -= a / b * x;
	return d;
}

bool solve(long long &m0, long long &a0, int m, int a)
{
	long long y, x;
	int g = extend_gcd(m0, m, x, y);
	int tmp = a - a0;
	if ( tmp < 0 )
	{
		tmp = -tmp;
	}
	if ( tmp % g )
		return false;
	x *= (a - a0) / g;
	x %= m / g;
	a0 = (x * m0 + a0);
	m0 *= m / g;
	a0 %= m0;
	if ( a0 < 0 )a0 += m0;
	return true;
}

bool MLES (long long &m0, long long &a0, int n) //½âÎª X = a0 + m0 * k
{
	bool flag = true;
	m0 = 1;
	a0 = 0;
	for (int i = 0; i < n; i++)
		if ( !solve(m0, a0, m[i], a[i]) )
		{
			flag = false;
			break;
		}
	return flag;
}

int main()
{
	int t;
	long long n;
	int m1;
	long long a0, m0;

	scanf( "%d", &t );

	while ( t-- )
	{
	    int con = 0;
		scanf( "%I64d%d", &n, &m1 );

		for ( int i = 0; i < m1; i++ )
		{
			scanf( "%d", &m[ i ] );
		}

		for ( int i = 0; i < m1; i++ )
		{
			scanf( "%d", &a[ i ] );
		}

		if ( !MLES( m0, a0, m1 ) )
		{
			printf( "0\n" );
		}
		else
		{
			while ( a0 <= 0 )
			{
				a0 += m0;
			}
			while ( a0 <= n )
			{
			    con += 1;
			    //printf( "     aaa\n" );
			    //printf( "     %ld\n", a0 );
				a0 += m0;
			}

			printf( "%d\n", con );
		}
	}
}
