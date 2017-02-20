#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 100 + 10;
bool vis[maxn];
int lowc[maxn];
int cost[maxn][maxn];
int prim(int n)
{
    int ans = 0;
    memset(vis, 0, sizeof(vis));
    vis[0] = 1;
    for (int i = 1; i < n; i++) lowc[i] = cost[0][i];
    for (int i = 1; i < n; i++)
    {
        int minc = INF;
        int p = -1;
        for (int j = 0; j < n; j++)
        {
            if (!vis[j] && minc > lowc[j])
            {
                minc = lowc[j];
                p = j;
            }
        }
        if (minc == INF) return -1;
        ans += minc;
        vis[p] = 1;
        for (int j = 0; j < n; j++)
        {
            if (!vis[j] && lowc[j] > cost[p][j])
            {
                lowc[j] = cost[p][j];
            }
        }
    }
    return ans;
}

int main()
{
    int n;
    int x, y;
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                scanf("%d", &cost[i][j]);
            }
        }
        int t;
        scanf("%d", &t);
        while (t--)
        {
            scanf("%d%d", &x, &y);
            cost[--x][--y] = cost [y][x] = 0;
        }
        printf("%d\n", prim(n));
    }
}
