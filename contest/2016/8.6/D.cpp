#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

const double INF = 0x3f3f3f3f;
const int maxn = 100 + 10;
bool vis[maxn];
double lowc[maxn];
double cost[maxn][maxn];
double prim(int n)
{
    double ans = 0;
    memset(vis, 0, sizeof(vis));
    vis[0] = 1;
    for (int i = 1; i < n; i++) lowc[i] = cost[0][i];
    for (int i = 1; i < n; i++)
    {
        double minc = INF;
        int p = -1;
        for (int j = 0; j < n; j++)
        {
            if (!vis[j] && minc > lowc[j])
            {
                minc = lowc[j];
                p = j;
            }
        }
        if (minc == INF) return -1;
        ans += minc;
        vis[p] = 1;
        for (int j = 0; j < n; j++)
        {
            if (!vis[j] && lowc[j] > cost[p][j])
            {
                lowc[j] = cost[p][j];
            }
        }
    }
    return ans;
}
struct point
{
    int x;
    int y;
}data[maxn];
double dist(point &a, point &b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
void builtcost(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            double d = dist(data[i], data[j]);
            //printf("%f\n", d);
            if (d > 1000.0 || d < 10.0)
            {
                //printf("%d %d\n", i, j);
                cost[i][j] = INF;
                cost[j][i] = INF;
            }
            else
            {
                cost[i][j] = d;
                cost[j][i] = d;
            }
        }
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        int x, y;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d", &data[i].x, &data[i].y);
        }
        builtcost(n);
        double res = prim(n);
        if (res == -1) printf("oh!\n");
        else printf("%.1f\n", res * 100);
    }
}
