#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 30 + 5;
bool a[maxn][maxn];
int con;
int dfscon;
int re;
bool vis[maxn];
bool read()
{
    while (1)
    {
        int n, m, t;
        if (scanf("%d%d", &n, &m) == EOF) return 0;
        con++;
        while (m--)
        {
            scanf("%d", &t);
            a[n][t] = 1;
        }
    }
}
int gett(int in, bool st)
{
    int ret = 0;
    for (int i = 1; i <= con; i++)
    {
        if (vis[i] != st || i == in) continue;
        if (!a[in][i]) ret++;
    }
    return ret;
}
int cal()
{
    int ret = 0;
    for (int i = 1; i <= con; i++)
    {
        ret = max(ret, gett(i, vis[i]));
    }
    return ret;
}
void dfs(int i)
{
    vis[i] = 1;
    dfscon++;
    if (dfscon == con / 2)
    {
        re = min(re, cal());
        vis[i] = 0;
        dfscon--;
        return;
    }
    for (int j = i + 1; j <= con; j++)
    {
        dfs(j);
    }
    vis[i] = 0;
    dfscon--;
    return;
}
int main()
{
    memset(a, 0, sizeof(a));
    memset(vis, 0, sizeof(vis));
    con = 0;
    read();
    //if (!read()) break;
    dfscon = 0;
    re = 0x3f3f3f3f;
    dfs(1);
    printf("%d\n", re);
}
