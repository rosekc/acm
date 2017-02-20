//2016-09-17-14.30
//qingdao inter 1011

#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn = 1000 + 10;
const int INF = 0x3f3f3f3f;
int g[maxn][maxn];
int vis[maxn];
struct data
{
    int p, t, w;
};
queue<data> q;
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, m;
        memset(g, 0x3f, sizeof(g));
        memset(vis, 0x3f, sizeof(vis));
        scanf("%d%d", &n, &m);
        while (m--)
        {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            g[u][v] = g[v][u] = w;
        }
        while (!q.empty()) q.pop();
        q.push({1, 0, INF});
        int ans = 0;
        int con = INF;
        bool flag = 0;
        while (1)
        {
            if (q.empty()) break;
            //puts("111");
            data &t = q.front();
            if (t.t > con) break;
            if (t.p == n)
            {
                //puts("123");
                if (!flag)
                {
                    flag = 1;
                    con = t.t;
                }
                ans += t.w;
            }
            for (int i = 2; i <= n; i++)
            {
                //printf("%d\n", g[t.p][i]);
                if (g[t.p][i] < INF && t.t + 1 <= vis[i])
                {
                    vis[i] = t.t + 1;
                    q.push({i, vis[i], min(g[t.p][i], t.w)});
                    //printf("     %d %d %d\n",t.p, i, min(g[t.p][i], t.w));
                }
            }
            q.pop();
        }
        printf("%d\n", ans);
    }
}
