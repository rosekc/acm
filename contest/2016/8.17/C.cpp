#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
const int maxn = 10000 + 10;
double vis[maxn];
int g[maxn][maxn];
struct data
{
    int p;
    double c;
    bool operator < (const data &b)const
    {
        return c < b.c;
    }
};
priority_queue<data> q;
int n, m;
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        memset(vis, 0, sizeof(vis));
        memset(g, 0, sizeof(g));
        while (!q.empty()) q.pop();
        scanf("%d%d", &n, &m);
        while (m--)
        {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            g[a][b] = g[b][a] = c;
        }
        q.push({1, 100});
        while (1)
        {
            if (q.top().p == n) break;
            for (int i = 1; i <= n; i++)
            {
                if (g[q.top().p][i] != 0 && vis[i] < q.top().c * g[q.top().p][i] / 100)
                {
                    vis[i] = q.top().c * g[q.top().p][i] / 100;
                    q.push({i, vis[i]});
                }
            }
            q.pop();
            if (q.empty()) break;
        }
        if (q.empty())
        {
            printf("0.000000\n");
        }
        else
        {
            printf("%.6f", q.top().c);
        }
    }
}
