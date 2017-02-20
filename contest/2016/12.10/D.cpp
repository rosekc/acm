//2016-12-10-11.30
//D

#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int dt[15], c[110], v[110];
int f[110][510];
int l, n, m;
int cal()
{
    memset(f, 0, sizeof f);
    for (int i = 1; i <= m; i++)
    {
        for (int j = 0; j < c[i]; j++)
        {
            f[i][j] = f[i - 1][j];
        }
        for (int j = c[i]; j <= l; j++)
        {
            for (int k = 0;;)
            {
                f[i][j] = max(f[i][j], f[i - 1][j - k * c[i]] + k * v[i]);
                k++;
                if (j - k * c[i] < 0) break;
            }
        }
    }
}
int getre(int i)
{
    return f[m][i];
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d%d", &l, &n, &m);
        dt[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &dt[i]);
        }
        dt[n + 1] = l;
        for (int i = 1; i <= m; i++)
        {
            scanf("%d%d", &c[i], &v[i]);
        }
        cal();
        int re = 0;
        for (int i = 1; i <= n + 1; i++)
        {
            re += getre(dt[i] - dt[i - 1]);
        }
        printf("%d\n", re);
    }
}
