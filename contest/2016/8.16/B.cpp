#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 500 + 10;
char g[maxn][maxn];
int vis[maxn][maxn];
int m, n, t;
int dfs(int i, int j)
{
    vis[i][j] = 1;
    int ret = 1;
    for (int l = 0; l < 8; l++)
    {
        int tr = i + mr[l];
        int tc = j + mc[l];
        if (tr >= 0 && tr < n && tc >= 0 && tc < m
         && !vis[tr][tc] && g[tr][tc] == '1')
        {
            ret += dfs(tr, tc);
        }
    }
    return ret;
}
int main()
{
    while (cin >> n >> m >> t)
    {
        memset(vis, 0, sizeof(vis));
        int con = 0;
        int ret = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> g[i][j];
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (g[i][j] == '1' && !vis[i][j])
                {
                    con++;
                    ret = max(dfs(i, j), ret);
                }
            }
        }
       cout << con << " " <<  ret * t;
    }
}
