#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 110;
bool vis[maxn];
int lowc[maxn];
int cost[maxn][maxn];
int b[maxn];
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
            if(!vis[j] && minc > lowc[j])
            {
                minc = lowc[j];
                p = j;
            }
        }
        if (minc == INF) return -1;
        ans += minc;
        vis[p] = 1;
        for(int j = 0; j < n; j++)
        {
            if (!vis[j] & lowc[j] > cost[p][j])
            {
                lowc[j] = cost[p][j];
            }
        }
    }
    return ans;
}

int main()
{
    int t;
    int n;
    scanf("%d", &t);
    while (t--)
    {
        //printf("123\n");
        scanf("%d", &n);
        int mint = INF;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &b[i]);
            mint = min(mint, b[i]);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                scanf("%d", &cost[i][j]);
                if (cost[i][j] > b[j]) cost[i][j] = b[j];

            }
        }
        printf("%d\n", prim(n) + mint);
    }
}
