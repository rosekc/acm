#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

#define INF 0x3f3f3f3f

const int maxn = 1000 + 5;
int a[maxn][maxn];
int indge[maxn];
int vis[maxn];
int n, m;
int maxd;
struct data
{
    int pos;
    int d;
    bool operator < (const data &a) const
    {
        return d > a.d;
    }
};
priority_queue<data> q;

void dfs()
{
    while (!q.empty())
    {
        data tmp = q.top();
        q.pop();
        for (int i = 0; i < n; i++)
        {
            //printf("456\n");
            if (a[tmp.pos][i] < INF)
            {
                vis[i] = max(vis[i], tmp.d + a[tmp.pos][i]);
                maxd = max(maxd, vis[i]);
                if (--indge[i] == 0) q.push({i, vis[i]});
            }
        }
        //printf("123\n");
    }
}

int main()
{
    int x, y, d;
    while (scanf("%d%d", &n, &m) != EOF && n + m != 0)
    {
        memset(indge, 0, sizeof(indge));
        memset(a, 0x3f, sizeof(a));
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d%d", &x, &y, &d);
            if (d < a[x][y])
            {
                indge[y]++;
                a[x][y] = d;
            }
        }
        for (int i = 0; i < n; i++)
        {
            //printf("444\n");
            if (indge[i] == 0)
            {
                q.push({i, 1});
                vis[i] = 1;
                maxd = 1;
            }
        }
        dfs();
        printf("%d\n", maxd);
    }
}
