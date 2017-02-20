//2016-11-23-00.30
//1003

#include <cstdio>
#include <cmath>
using namespace std;

long long lowbit(long long x)
{
    return x & (-x);
}

int main()
{
    long long re, num;
    long long h, n;
    while (scanf("%lld%lld", &h, &n) != EOF)
    {
        re = 1;
        num = 1;
        n--;
        for (int i = 0; i < h; i++)
        {
            if (lowbit(n >> (h - i - 1)) == 1) num += (long long)1 << (h - i);
            else num++;
            //printf("%lld\n", num);
            re += num;
            re %= int(1e9 + 7);
            //printf("   %lld %d\n", n, i);
        }
        printf("%lld\n", re);
    }
}
