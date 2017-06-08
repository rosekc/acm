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
        if (g[u][v] && !used[v])
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
        if(dfs(u)) res++;
    }
    return res;
}

int main()
{
    while (scanf("%d%d", &un, &vn) != EOF)
    {
        memset(g, 0, sizeof(g));
        for (int i = 0; i < un; i++)
        {
            int t;
            scanf("%d", &t);
            while (t--)
            {
                int tt;
                scanf("%d", &tt);
                g[i][tt - 1] = 1;
            }
        }
        printf("%d\n", hungary());
    }
}
