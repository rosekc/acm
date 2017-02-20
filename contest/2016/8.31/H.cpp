#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 100 + 10;
int g[maxn][maxn];
int vis[maxn];
struct data
{
    int p;
    int d;
};

queue<data> qu;

int main()
{
    int c, s, q;
    int con = 1;
    while (scanf("%d%d%d", &c, &s, &q) != EOF && c + s + q != 0)
    {
        memset(g, 0x3f, sizeof(g));
        while (s--)
        {
            int x, y, d;
            scanf("%d%d%d", &x, &y, &d);
            if (d > 80) continue;
            g[x][y] = g[y][x] = d;
        }
        printf("Case #%d\n", con++);
        while (q--)
        {
            memset(vis, 0x3f, sizeof(vis));
            int st, ed;
            scanf("%d%d", &st, &ed);
            for (int i = 1; i <= c; i++)
            {
                if (g[st][i] <= 80)
                {
                    qu.push({i, g[st][i]});
                    vis[i] = g[st][i];
                }
            }
            if (qu.empty())
            {
                printf("no path\n");
                continue;
            }
            while (1)
            {
                data t = qu.front();
                qu.pop();
                for (int i = 1; i <= c; i++)
                {
                    if (g[t.p][i] <= 80 && max(t.d, g[t.p][i]) < vis[i])
                    {
                        vis[i] = max(t.d, g[t.p][i]);
                        qu.push({i, vis[i]});
                    }
                }
                if (qu.empty()) break;
            }
            if (vis[ed] > 80) printf("no path\n");
            else printf("%d\n", vis[ed]);
        }
    }
}
