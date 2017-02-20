#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

#define INF 0x3f3f3f3f

const int maxn = 1000 + 5;
int a[maxn][maxn];
int b[maxn][maxn];
int vis[maxn];
int n, m;
int st, ed;
struct data
{
    int pos;
    int d;
    int p;
    bool operator < (const data &a) const
    {
        if (d == a.d)
        {
            return p > a.p;
        }
        else return d > a.d;
    }
};
priority_queue<data> q;

void dfs()
{
    while (1)
    {
        data tmp = q.top();
        //printf("%d %d %d\n", tmp.pos, tmp.d, tmp.p);
        if (tmp.pos == ed) return;
        else q.pop();
        for (int i = 1; i <= n; i++)
        {
            if (a[tmp.pos][i] < INF && vis[i] >= tmp.d + a[tmp.pos][i])
            {
                //printf("Push:%d %d %d\n", i, tmp.d + a[tmp.pos][i], tmp.p + b[tmp.pos][i]);
                q.push({i, tmp.d + a[tmp.pos][i], tmp.p + b[tmp.pos][i]});
                vis[i] = tmp.d + a[tmp.pos][i];
            }
        }
    }
}

int main()
{
    int x, y, d, p;
    while (scanf("%d%d", &n, &m) != EOF && n + m != 0)
    {
        memset(a, 0x3f, sizeof(a));
        memset(vis, 0x3f, sizeof(vis));
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d%d%d", &x, &y, &d, &p);
            if (d < a[x][y])
            {
                a[x][y] = a[y][x] = d;
                b[x][y] = b[y][x] = p;
            }
            else if (d == a[x][y] && p < b[x][y]) b[x][y] = b[y][x] = p;
        }
        scanf("%d%d", &st, &ed);
        q.push({st, 0, 0});
        vis[st] = 1;
        dfs();
        printf("%d %d\n", q.top().d, q.top().p);
        while (!q.empty()) q.pop();
    }
}
