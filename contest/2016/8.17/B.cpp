#include <cstdio>

const int maxn = 100005;
int d[maxn];

int main()
{
    int t;
    scanf("%d", &t);
    d[0] = 0;
    d[1] = 1;
    int tmp = 5;
    for (int i = 2; i < maxn; i++)
    {
        d[i] = tmp % 997;
        tmp += 5;
    }
    while (t--)
    {
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        printf("%d %d\n", d[m - 1], d[n - m + 1 - k]);
    }
}
