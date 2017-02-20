//2016-09-28-22.18
//UVA 1583

#include <cstdio>
using namespace std;

const int maxn = 100000 + 10;
int d[maxn];
int getsum(int n)
{
    int ret = 0;
    while (n >= 10)
    {
        ret += n % 10;
        n /= 10;
    }
    ret += n;
    return ret;
}
int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= maxn; i++)
    {
        int tmp = i + getsum(i);
        if (tmp >= maxn) break;
        if (d[tmp] == 0) d[tmp] = i;
    }
    while (t--)
    {
        int n;
        scanf("%d", &n);
        printf("%d\n", d[n]);
    }
}
