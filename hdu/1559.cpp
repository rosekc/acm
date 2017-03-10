//2017-03-09-23.46
//HDU 1559

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000 + 5;
int d[maxn][maxn];
int sum[maxn][maxn];
int t, m, n, x, y;

int cal(int r, int c)
{
    int re = 0;
    for (int i = r; i < r + x; i++)
    {
        re += (sum[i][c + y - 1] - sum[i][c - 1]);
    }
    return re;
}

int main()
{

    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d%d%d", &m, &n, &x, &y);
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
        {
            scanf("%d", &d[i][j]);
            if (j == 1)
            {
                sum[i][j] = d[i][j];
            }
            else sum[i][j] = sum[i][j - 1] + d[i][j];
        }
        int re = -1;
        for (int i = 1; i <= m - x + 1; i++)
            for (int j = 1; j <= n - y + 1; j++)
        {
            re = max(re, cal(i, j));
        }
        printf("%d\n", re);
    }
}
