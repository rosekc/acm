#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 500 + 10;
int g[maxn][maxn];
int vis[maxn];
int m, n, t;
struct data
{
    int p;
    int t;
    int line;
    bool operator <(const data &b)const
    {
        return t > b.t;
    }

};
priority_queue<data> q;
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        memset(vis, 0x3f, sizeof(vis));
        memset(g, 0, sizeof(g));
        while (!q.empty()) q.pop();
        scanf("%d%d", &m, &n);
        for (int i = 1; i <= m; i++)
        {
            int a, b;
            char c;
            scanf("%d", &a);
            while ((c = getchar()) != '\n')
            {
                scanf("%d", &b);
                //printf("%d %d\n", i, b);
                g[a][b] = i;
                if (a == 1)
                {
                    q.push({1, 0, i});
                }
                a = b;
            }
        }
        int ret = -1;
        while (1)
        {
            data t = q.top();
            //printf("%d %d %d\n", t.p, t.t, t.line);
            if (t.p == n)
            {
                ret = t.t;
                break;
            }
            for (int i = 1; i <= n; i++)
            {
                if (g[t.p][i] != 0)
                {
                    int tt = t.t;
                    if (t.line != g[t.p][i]) tt++;
                    if (tt <= vis[i])
                    {
                        vis[i] = tt;
                        //printf("%d\n", i);
                        q.push({i, tt, g[t.p][i]});
                    }
                }
            }
            q.pop();
            if (q.empty()) break;
        }
        if (ret == -1) printf("NO\n");
        else printf("%d\n", ret);
    }
}
