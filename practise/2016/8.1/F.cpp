#include <cstdio>
#include <queue>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

#define INF 0x3f3f3f3f

const int maxn = 1000 + 5;
bool a[maxn][maxn];
int b[maxn];
int indge[maxn];
node vis[maxn];
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
struct node
{
    int d;
    string way;
};
priority_queue<data> q;

void dfs()
{
    while (!q.empty())
    {
        data tmp = q.top();
        q.pop();
        if (tmp.pos = n + 1)
        for (int i = 1; i <= n + 1; i++)
        {
            //printf("456\n");
            if (a[tmp.pos][i] < INF)
            {
                if (vis[i].d < tmp.d + b[i])
                {
                    vis[i].d = tmp.d + b[i];
                    vis[i].way = vis[tmp.pos].way + char(i - '0');
                }
                if (--indge[i] == 0) q.push({i, vis[i]});
            }
        }
        //printf("123\n");
    }
}

int main()
{
    int t;
    int x, y, d;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &b[i]);
        }
        memset(indge, 0, sizeof(indge));
        memset(a, 0, sizeof(a));
        memset(vis, 0, sizeof(vis));
        scanf("%d", &m);
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d%d", &x, &y);
            if (!a[x][y])
            {
                indge[y]++;
                a[x][y] = 1;
            }
        }
        q.push({1, 1, "1"});
        vis[i] = 0;
        maxd = 0;
        dfs();
        printf("%d\n", maxd);
    }
}
