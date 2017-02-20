#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 1000 + 5;
int g[maxn][maxn];
int ed[maxn];
int vis[maxn];
int aim[maxn];
int a, b, c;
struct data
{
    int pos;
    int t;
    bool operator < (const data &a) const
    {
        return t > a.t;
    }
};
priority_queue<data> q;
bool check(int p)
{
    //printf("%d\n", p);
    for (int i = 0; i < c; i++)
    {
        if (aim[i] == p) return 1;
    }
    return 0;
}
void dfs()
{
    for (;;)
    {
        data tmp = q.top();
        //printf("%d\n", tmp.pos);
        if (check(tmp.pos)) return;
        else q.pop();
        for (int i = 1; i <= 1000; i++)
        {
            if (g[tmp.pos][i] < INF && vis[i] >= tmp.t + g[tmp.pos][i])
            {
                q.push({i, g[tmp.pos][i] + tmp.t});
                vis[i] = tmp.t + g[tmp.pos][i];
            }
        }
        //printf("123\n");
    }
}

int main()
{
    int x, y, t;
    while (scanf("%d%d%d", &a, &b, &c) != EOF)
    {
        memset(g, 0x3f, sizeof(g));
        memset(vis, 0x3f, sizeof(vis));
        while (!q.empty()) q.pop();
        while (a--)
        {
            scanf("%d%d%d", &x, &y, &t);
            if (t < g[x][y])
            {
                g[x][y] = g[y][x] = t;
            }
        }
        while (b--)
        {
            scanf("%d", &x);
            q.push({x, 0});
            vis[x] = 0;
        }
        for (int i = 0; i < c; i++)
        {
            scanf("%d", &aim[i]);
        }
        dfs();
        printf("%d\n", q.top().t);
    }
}
