#include <cstdio>
#include <sstream>
#include <cmath>
typedef long long LL;

using namespace std;

LL e_gcd(LL a,LL b,LL &x,LL &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    LL ans=e_gcd(b,a%b,x,y);
    LL temp=x;
    x=y;
    y=temp-a/b*y;
    return ans;
}

LL cal(LL a,LL b,LL c)
{
    LL x,y;
    LL gcd=e_gcd(a,b,x,y);
    if(c%gcd!=0) return -1;
    x*=c/gcd;
    b/=gcd;
    if(b<0) b=-b;
    LL ans=x%b;
    if(ans<=0) ans+=b;
    return ans;
}


LL pow_mod(LL a, long long x, long long p)
{
	LL ans = 1;
	while (x)
	{
		if (x & 1)
		{
			ans = ans * a % p;
		}
		a = a * a % p;
		x >>= 1;
	}
	return ans;
}

char re[ 10000000 ];

int main()
{
	long long p, q, e, l;
	stringstream ss;

	while ( scanf( "%I64d%I64d%I64d%I64d", &p, &q, &e, &l ) != EOF )
	{
		long long n = p * q;
		long long fn = ( p - 1 ) * ( q - 1 );
		long long d = cal( e, fn, 1 ) ;
		LL tmp;

		//printf( "%I64d\n", d );

		int j = 0;

		for ( int i = 0; i < l; i++ )
		{
		    scanf( "%I64d", &tmp );

			re[ j++ ] = char( pow_mod( tmp, d, n ) );

			if ( i == l - 1 )
			{
				re[ j ] = '\0';
				break;
			}
		}

		printf( "%s\n", re );
	}
}
