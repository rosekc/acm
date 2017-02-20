#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 500 + 10;
int un, vn;
bool g[maxn][maxn];
int linker[maxn];
bool used[maxn];

bool dfs(int u)
{
    for (int v = 0; v < vn; v++)
    {
        if (!g[u][v] && !used[v])
        {
            used[v] = 1;
            if (linker[v] == -1 || dfs(linker[v]))
            {
                linker[v] = u;
                return 1;
            }
        }
    }
    return 0;
}
int hungary()
{
    int res = 0;
    memset(linker, -1, sizeof(linker));
    for (int u = 0; u < un; u++)
    {
        memset(used, 0, sizeof(used));
        if (dfs(u)) res++;
    }
    return res;
}

int main()
{
    int t, e;
    int con = 1;
    scanf("%d", &t);
    while (t--)
    {
        memset(g, 0, sizeof(g));
        scanf("%d%d%d", &un, &vn, &e);
        while (e--)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            g[--x][--y] = 1;
        }
        printf("Case %d: %d\n", con++, hungary());
    }
}
