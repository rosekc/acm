//2017-01-19-23.38
//C

#include <cstdio>
using namespace std;

int main()
{
    int n, m, x, y;
    long long k;
    while (scanf("%d%d%lld%d%d", &n, &m, &k, &x, &y) != EOF)
    {
        if (n == 1)
        {
            long long t = k / m;
            int a = k % m;
            long long mx = t, mn = t, re = t;
            if (a > 0) mx++;
            if (a >= y) re++;
            printf("%lld %lld %lld\n", mx, mn, re);
            continue;
        }
        int w = (2 * n - 2) * m;
        long long t = k / w;
        long long mx = 2 * t, mn = t, re;
        if (n == 2) mx = t, mn = t;
        int a = k % w;
        if (x != 1 && x != n)
        {
            re = mx;
        }
        else re = mn;
        //printf("%d %d\n", a, t);
        if (a > 0 && a <= m)
        {
            if (x == 1 && y <= a) re++;
            if (n == 2) mx++;
            if (t == 0) mx = 1;
        }
        else if (a > m && a < n * m)
        {
            if (y <= a - x * m + m)
            {
                re++;
            }
            mx++;
        }
        else if (a >= n * m)
        {
            re++;
            if (x != 1 && x != n)
            {
                if (y <= a - m * n - (n - 1 - x) * m) re++;
            }
            mx++;
            if (a > n * m) mx++;
            mn++;
        }
        printf("%lld %lld %lld\n", mx, mn, re);
    }
}
