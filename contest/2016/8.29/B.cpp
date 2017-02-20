#include <cstdio>
#include <queue>
#include <cstring>
#include <stack>
using namespace std;
int g[5][5];
int vis[5][5];
int wr[4] = {-1, 0, 1, 0};
int wc[4] = {0, 1, 0, -1};
struct data
{
    int x;
    int y;
};
data w[5][5];
queue<data> q;
stack<data> s;
int main()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            scanf("%d", &g[i][j]);
        }
    }
    memset(vis, 0x3f, sizeof(vis));
    memset(w, -1, sizeof(w));
    while (!q.empty()) q.pop();
    q.push({0, 0});
    vis[0][0] = 0;
    while (1)
    {
        bool flag = 0;
        data t = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int tr = t.x + wr[i];
            int tc = t.y + wc[i];
            if (tr >= 0 && tr < 5 && tc >= 0 && tc < 5 &&
                    g[tr][tc] == 0 && vis[t.x][t.y] + 1 < vis[tr][tc])
            {
                q.push({tr, tc});
                vis[tr][tc] = vis[t.x][t.y] + 1;
                w[tr][tc] = {t.x, t.y};
            }
            if (tr == 4 && tc == 4)
            {
                flag = 1;
                break;
            }
        }
        if (flag) break;
    }
    data p = {4, 4};
    //printf("(0, 0)\n");
    s.push({4, 4});
    while (1)
    {
        for (int i = 0; i < 4; i++)
        {
            int tr = p.x + wr[i];
            int tc = p.y + wc[i];
            if (tr >= 0 && tr < 5 && tc >= 0 && tc < 5 &&
                w[p.x][p.y].x == tr && w[p.x][p.y].y == tc)
            {
                s.push({tr, tc});
                p = {tr, tc};
                break;
            }
        }
        if (p.x == 0 && p.y == 0)
        {
            //printf("(4, 4)\n");
            break;
        }
    }
    while (!s.empty())
    {
        printf("(%d, %d)\n", s.top().x, s.top().y);
        s.pop();
    }
}
