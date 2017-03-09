//2017-02-21-22.50
//Uva 201

#include <bits/stdc++.h>

using namespace std;

const int maxn = 30;
bool h[maxn][maxn], v[maxn][maxn];
int re[maxn];
int n, m;
int checkh(int x, int y)
{
    int ans = 0;
    while (h[x][y]) ans++, y++;
    //printf("%d %d h:%d\n", x, y - ans, ans);
    return ans;
}
int checkv(int x, int y)
{
    int ans = 0;
    while (v[x][y]) ans++, x++;
    //printf("%d %d v:%d\n", x - ans, y, ans);
    return ans;
}
void finds(int x, int y)
{
    for (int i = 1; i <= n; i++)
    {
        if (checkh(x, y) >= i && checkh(x + i, y) >= i &&
            checkv(x, y) >= i && checkv(x, y + i) >= i)
        {
            re[i]++;
            //printf("%d %d %d\n", x, y, i);
        }
    }
}
int main()
{
    bool isfirst = 1;
    int kase = 1;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        memset(h, 0, sizeof h);
        memset(v, 0, sizeof v);
        memset(re, 0, sizeof re);
        char in[3];
        int x, y;
        while (m--)
        {
            scanf("%s%d%d", in, &x, &y);
            if (in[0] == 'H')
            {
                h[x][y] = 1;
            }
            else
            {
                v[y][x] = 1;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                finds(i, j);
            }
        }
        if (isfirst) isfirst = 0;
        else puts("\n**********************************\n");
        printf("Problem #%d\n\n", kase++);
        bool f = 0;
        for (int i = 1; i <= n; i++)
        {
            if (re[i] != 0)
            {
                f = 1;
                printf("%d square (s) of size %d\n", re[i], i);
            }
        }
        if (!f) puts("No completed squares can be found.");
    }
}
