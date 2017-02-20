//2016-11-18-20.11
//hdu1010

#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

char m[10][10];
bool vis[10][10];
int dr[] = { -1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
int r, c, t;
int stx, sty, edx, edy;
bool check(int x, int y)
{
    if (x >= 0 && x < r &&
            y >= 0 && y < c &&
            m[x][y] != 'X' && !vis[x][y]) return 1;
    else return 0;
}
bool dfs(int x, int y, int p)
{
    vis[x][y] = 1;
    if (m[x][y] == 'D' && p == t) return 1;
    for (int i = 0; i <= 3; i++)
    {
        int tx = x + dr[i];
        int ty = y + dc[i];
        if (check(tx, ty) && p < t)
        {
            if (dfs(tx, ty, p + 1)) return 1;
        }
    }
    vis[x][y] = 0;
    return 0;
}

int main()
{
    while (scanf("%d%d%d", &r, &c, &t) != EOF && r)
    {
        memset(vis, 0, sizeof(vis));
        getchar();
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                scanf("%c", &m[i][j]);
                //puts("2333");
                if (m[i][j] == 'S')
                {
                    stx = i;
                    sty = j;
                }
                if (m[i][j] == 'D')
                {
                    edx = i;
                    edy = j;
                }
            }
            getchar();
        }
        int tmp = (abs(stx - edx) + abs(sty - edy));
        if (tmp % 2 != (t % 2))
        {
            puts("NO");
            continue;
        }
        if (dfs(stx, sty, 0)) puts("YES");
        else puts("NO");
    }
}
