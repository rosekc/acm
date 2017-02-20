#include <cstdio>
#include <set>
using namespace std;
const int MAXN = 200000 + 5;
#define typec int
const typec INF = 0x3f3f3f3f; //防止后面溢出，这个不能太大
bool vis[MAXN];
int pre[MAXN];
struct edge
{
    int x, y;
    bool operator <(const edge &b)const
    {
        return this->x < b.x;
    }
};
set<edge> s;
int lowcost[MAXN];
void Dijkstra( int n, int beg)
{
    for (int i = 0; i < n; i++)
    {
        lowcost[i] = INF;
        vis[i] = false;
        pre[i] = -1;
    }
    lowcost[beg] = 0;
    for (int j = 0; j < n; j++)
    {
        int k = -1;
        int Min = INF;
        for (int i = 0; i < n; i++)
            if (!vis[i] && lowcost[i] < Min)
            {
                Min = lowcost[i];
                k = i;
            }
        if (k == -1) break;
        vis[k] = true;
        int cost;
        for (int i = 0; i < n; i++)
        {
            if (s.find({k, i}) != s.end() || s.find({i, k}) != s.end()) cost = INF;
            else cost = 1;
            if (!vis[i] && lowcost[k] + cost < lowcost[i])
            {
                lowcost[i] = lowcost[k] + cost;
                pre[i] = k;
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
        int n, m, beg;
        s.clear();
        scanf("%d%d", &n, &m);
        while (m--)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            x--; y--;
            s.insert({x, y});
        }
        scanf("%d", &beg);
        Dijkstra(n, --beg);
        for (int i = 0; i < n; i++)
        {
            if (i == beg) continue;
            if (lowcost[i] < INF) printf("%d", lowcost[i]);
            else printf("-1");
            if (i != n - 1) printf(" ");
        }
        printf("\n");
    }
}
