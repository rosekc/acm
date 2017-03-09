//2017-02-25-20.19
//1003

#include <bits/stdc++.h>

using namespace std;
char in[110];
int f[101][101][51], p[101], cnt, t, n, m, dfn[101][101][51], kasei;
int dfs(int k, int lp, int tim)
{
    if (k > cnt)
    {
        //puts("aaa");
        return (n - lp >= 2);
    }
    if (dfn[k][lp][tim] == kasei) return f[k][lp][tim];
    dfn[k][lp][tim] = kasei;
    f[k][lp][tim] = -1e9;
    int left = max(p[k] - tim, lp + 1), rigth = min(p[k] + tim, n);
    //printf("l:%d r:%d\n", left, rigth);
    for (int i = left; i <= rigth; i++)
    {
        int cost = abs(p[k] - i);
        f[k][lp][tim] = max(dfs(k + 1, i, tim - cost) + (i - lp >= 3) * (k > 1),
                            f[k][lp][tim]);
    }
    //printf("%d %d\n", k, f[k][lp][tim]);
    return f[k][lp][tim];
}
int main()
{
    scanf("%d", &t);
    kasei = 1;
    while (t--)
    {
        scanf("%d%d%s", &n, &m, in + 1);
        m /= 2;
        cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (in[i] == '2') p[++cnt] = i;
        }
        if (cnt == 0)
        {
            puts("0");
            continue;
        }
        printf("%d\n", dfs(1, 0, m));
        kasei++;
    }
}
