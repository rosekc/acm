#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int m, n, x, y;
int a[1005][1005];
int cal(int i, int j)
{
    int sum = 0;
    for (int k = 0; k < x; k++)
    {
        for (int l = 0; l < y; l++)
        {
            sum += a[i + k][j + l];
        }
    }
    return sum;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int ret = 0;
        scanf("%d%d%d%d", &m, &n, &x, &y);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                scanf("%d", &a[i][j]);
            }
        }
        for (int i = 0; i <= m - x; i++)
        {
            for (int j = 0; j <= n - y; j++)
            {
                ret = max(ret, cal(i, j));
            }
        }
        printf("%d\n", ret);
    }
}
