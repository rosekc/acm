//2016-12-10-13.16
//F

#include <cstdio>
using namespace std;
const int maxn = 2000000 + 10;
int d[maxn];
int main()
{
    d[1] = 1;
    for (int i = 2; i < maxn; i++)
    {
        long long t = (long long)(d[i - 1]) * (i - 1) ;
        d[i] = (t % 1000000007 + (i - 2)) % 1000000007;
        //printf("%d\n", d[i]);
    }
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        printf("%d\n", d[n]);
    }
}
