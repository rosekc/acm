#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 1100;
int g[MAXN][MAXN];
int gap[MAXN], dis[MAXN], pre[MAXN], cur[MAXN];

int sap(int st, int ed, int nodenum)
{
	memset(cur, 0, sizeof(cur));
	memset(dis, 0, sizeof(dis));
	memset(gap, 0, sizeof(gap));
	int u = pre[st] = st, maxflow = 0, aug = -1;
	gap[0] = nodenum;
	while (dis[st] < nodenum)
    {
        loop:
            for(int v = cur[u]; v < nodenum; v++)
            {
                if (g[u][v] && dis[u] == dis[v] + 1)
                {
                    if (aug == -1 || aug > g[u][v]) aug = g[u][v];
                    pre[v] = u;
                    u = cur[u] = v;
                    if (v == ed)
                    {
                        maxflow += aug;
                        for (u = pre[u]; v != st; v = u, u = pre[u])
                        {
                            g[u][v] -= aug;
                            g[v][u] += aug;
                        }
                        aug = -1;
                    }
                    goto loop;
                }
            }
            int mindis = nodenum - 1;
            for (int v = 0; v < nodenum; v++)
            {
                if(g[u][v] && mindis > dis[v])
                {
                    cur[u] = v;
                    mindis = dis[v];
                }
            }
            if((--gap[dis[u]]) == 0) break;
            gap[dis[u] = mindis + 1]++;
            u = pre[u];
    }
    return maxflow;
}

int main()
{
    int n, m;
    int a, b, c;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        memset(g, 0, sizeof(g));
        while (n--)
        {
            scanf("%d%d%d", &a, &b, &c);
            g[a - 1][b - 1] += c;
        }
        printf("%d\n", sap(0, m - 1, m));
    }
}
