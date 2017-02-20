#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

const int maxn = 100 + 10;
bool data[maxn][maxn];
bool vis[maxn];
int a[maxn];
int indge[maxn];
queue<int> q;

int main()
{
    int n, m;
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &m);
        memset(data, 0, sizeof(data));
        memset(indge, 0, sizeof(indge));
        memset(vis, 0, sizeof(vis));
        memset(a, 0, sizeof(a));
        int x, y;
        int res = 0;
        for (int i = 0; i < m; i ++)
        {
            scanf("%d%d", &x, &y);
            if(x == y) continue;
            if (data[--x][--y] == 0)
            {
                indge[y]++;
                data[x][y] = 1;
                //printf("%d %d\n", x, y);
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (indge[i] == 0)
            {
                q.push(i);
                vis[i] = 1;
                res++;
                //printf("  %d\n", i);
            }
        }
        while (!q.empty())
        {
            int p = q.front();
            q.pop();
            for (int i = 0; i < n; i++)
            {
                if(data[p][i])
                {
                    if (--indge[i] == 0 && !vis[i])
                    {
                        vis[i] = 1;
                        a[p]++;
                        if (a[p] > res) res++;
                        //printf("   %d\n", i);
                        q.push(i);
                    }
                }
            }
        }
        printf("%d\n", res);
    }
}
