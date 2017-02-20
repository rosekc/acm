#include <cstdio>
using namespace std;
const int maxn = 10100;
const int INF = 0x3f3f3f3f;
int g[maxn][maxn];

int n, m;
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i == j) g[i][j] = 0;
                else g[i][j] = 0;
            }
        }
        while (m--)
        {
            int a, b;
            int c;
            scanf("%d%d%d", &a, &b, &c);
            g[a][b] = g[b][a] = c;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                printf("%d ", g[i][j]);
            }
            puts("");
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                for (int k = 1; k <= n; k++)
                {
                    if(g[j][k] < g[j][i] * g[i][k])
                    {
                        g[j][k] = g[j][i] * g[i][k];
                    }
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                printf("%d ", g[i][j]);
            }
            puts("");
        }
        //if (g[1][n] >= INF) printf("0.000000\n");
        printf("%d", g[1][n]);
    }
}
