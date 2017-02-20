#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

#define INF 0x3f3f3f3f

const int maxn = 200 + 5;
int a[maxn][maxn];
int vis[maxn];
int n, m;
int st, ed;
struct data
{
    int pos;
    int d;
    bool operator < (const data &a) const
    {
        return this->d > a.d;
    }
};
priority_queue<data> q;

bool dfs()
{
    while (!q.empty())
    {
        data tmp = q.top();
        //printf("%d %d %d\n", tmp.pos, tmp.d, tmp.p);
        if (tmp.pos == ed) return 1;
        else q.pop();
        for (int i = 1; i <= n; i++)
        {
            if (a[tmp.pos][i] < INF && vis[i] >= tmp.d + a[tmp.pos][i])
            {
                //printf("Push:%d %d %d\n", i, tmp.d + a[tmp.pos][i], tmp.p + b[tmp.pos][i]);
                q.push({i, tmp.d + a[tmp.pos][i]});
                vis[i] = tmp.d + a[tmp.pos][i];
            }
        }
    }
    return 0;
}

int main()
{
    int x, y, d;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        memset(a, 0x3f, sizeof(a));
        memset(vis, 0x3f, sizeof(vis));
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d%d", &x, &y, &d);
            if (d < a[x][y])
            {
                a[x][y] = a[y][x] = d;
            }
        }
        scanf("%d%d", &st, &ed);
        q.push({st, 0});
        vis[st] = 0;
        if (dfs()) printf("%d\n", q.top().d);
        else printf("-1\n" );
        while (!q.empty()) q.pop();
    }
}
