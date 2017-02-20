//2016-12-31-00.05
//D

#include <cstdio>
#include <set>
#include <cstring>
using namespace std;
int mr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int mc[] = {0, 1, 1, 1, 0, -1, -1, -1};
struct point
{
    int x, y;
    bool operator < (const point& b)const
    {
        if (x == b.x) return y < b.y;
        else return x < b.x;
    }
};
set<point> vis1;
bool vis[305][305][8][6][31];
int d[35];
int n;
void dfs(int x, int y, int fo, int stp, int cur)
{
    if (vis[x][y][fo][stp][cur]) return;
    vis[x][y][fo][stp][cur] = 1;
    vis1.insert({x, y});
    //printf("%d %d %d %d %d\n", x, y, fo, stp, cur);
    if (stp != 0)
    {
        dfs(x + mr[fo], y + mc[fo], fo, stp - 1, cur);
    }
    else if (cur != n - 1)
    {
        int fo1 = (fo + 1) % 8, fo2 = (fo + 7) % 8;
        cur++;
        dfs(x + mr[fo1], y + mc[fo1], fo1, d[cur] - 1, cur);
        dfs(x + mr[fo2], y + mc[fo2], fo2, d[cur] - 1, cur);
    }
}
int main()
{
    while (scanf("%d", &n) != EOF)
    {
        memset(vis, 0, sizeof(vis));
        vis1.clear();
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &d[i]);
        }
        dfs(150, 150, 0, d[0] - 1, 0);
        printf("%d\n", vis1.size());
    }
}
