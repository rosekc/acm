//2016-11-19-00.02
//hdu 2544

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 150, INF = 0x3f3f3f3f;
int d[MAXN], w[MAXN][MAXN], n;
bool v[MAXN];
void dijkstra()
{
    memset(v, 0, sizeof(v));
    memset(d, 0x3f, sizeof(d));
    d[1] = 0;
    for (int i = 0; i < n; i++)
    {
        int x, m = INF;
        for (int y = 1; y <= n; y++) if (!v[y] && m > d[y]) m = d[x = y];
        v[x] = 1;
        for (int y = 1; y <= n; y++)
        {
            if (d[y] > d[x] + w[x][y])
            {
                d[y] = d[x] + w[x][y];
            }
        }
    }
}
int main()
{
    int m, x, y, t;
    while (scanf("%d%d", &n, &m) != 0 && n)
    {
        memset(w, 0x3f, sizeof(w));
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d%d", &x, &y, &t);
            w[x][y] = w[y][x] = min(w[x][y], t);
        }
        dijkstra();
        printf("%d\n", d[n]);
    }
}
