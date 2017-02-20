#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 1510;//点数的最大值
const int MAXM = 15010;//边数的最大值
struct Edge
{
    int to, next;
} edge[MAXM];
int head[MAXN], tot;
void init()
{
    tot = 0;
    memset (head, -1, sizeof(head));
}
void addedge(int u, int v)
{
    edge[tot].to = v;
    edge[tot].next = head[u];
    head[u] = tot++;
}
int linker[MAXN];
bool used[MAXN];
int n;
bool dfs(int u)
{
    for (int i = head[u]; i != -1 ; i = edge[i].next)
    {
        int v = edge[i].to;
        if (!used[v])
        {
            used[v] = true;
            if (linker[v] == -1 || dfs(linker[v]))
            {
                linker[v] = u;
                return true;
            }
        }
    }
    return false;
}
int hungary()
{
    int res = 0;
    memset (linker, -1, sizeof(linker));
    for (int u = 0; u < n; u++)
    {
        memset (used, false, sizeof(used));
        if (dfs(u)) res++;
    }
    return res;
}
int main()
{
    while (scanf("%d", &n) != EOF)
    {
        init();
        for (int i = 0; i < n; i++)
        {
            int x, t;
            scanf("%d:(%d)", &x, &t);
            while (t--)
            {
                int tt;
                scanf("%d", &tt);
                addedge(x, tt);
                addedge(tt, x);
            }
        }
        printf("%d\n", hungary() / 2);
    }
}
