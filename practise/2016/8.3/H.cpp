#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 300 + 10;
const int INF = 0x3f3f3f3f;
int nx, ny;
int g[maxn][maxn];
int linker[maxn], lx[maxn], ly[maxn];
int slack[maxn];
bool visx[maxn], visy[maxn];

bool dfs(int x)
{
    visx[x] = 1;
    for (int y = 0; y < ny; y++)
    {
        if (visy[y]) continue;
        int tmp = lx[x] + ly[y] - g[x][y];
        if (tmp == 0)
        {
            visy[y] = 1;
            if (linker[y] == -1 || dfs(linker[y]))
            {
                linker[y] = x;
                return 1;
            }
        }
        else if (slack[y] > tmp) slack[y] = tmp;
    }
    return 0;
}
int km()
{
    memset(linker, -1, sizeof(linker));
    memset(ly, 0, sizeof(ly));
    for (int i = 0; i < nx; i++)
    {
        lx[i] = -INF;
        for (int j = 0; j < ny; j++)
        {
            if(g[i][j] > lx[i]) lx[i] = g[i][j];
        }
    }
    for (int x = 0; x < nx; x++)
    {
        for (int i = 0; i < ny; i++)
        {
            slack[i] = INF;
        }
        while (1)
        {
            memset(visx, 0, sizeof(visx));
            memset(visy, 0, sizeof(visy));
            if (dfs(x)) break;
            int d = INF;
            for (int i = 0; i < ny; i++)
            {
                if(!visy[i] && d > slack[i]) d = slack[i];
            }
            for (int i = 0; i < nx; i++)
            {
                if (visx[i]) lx[i] -= d;
            }
            for (int i = 0; i < ny; i++)
            {
                if (visy[i]) ly[i] += d;
                else slack[i] -= d;
            }
        }
    }
    int res = 0;
    for (int i = 0; i < ny; i++)
    {
        if (linker[i] != -1) res += g[linker[i]][i];
    }
    return res;
}

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                scanf("%d", &g[i][j]);
            }
        }
        nx = ny = n;
        printf("%d\n", km());
    }
}
