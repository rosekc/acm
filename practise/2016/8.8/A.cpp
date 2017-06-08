#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100 + 10;
int g[maxn][maxn];
int sum[maxn][maxn];

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                scanf("%d", &g[i][j]);
            }
        }

        for (int j = 0; j < n; j++)
        {
            sum[n - 1][j] = g[n - 1][j];
        }
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = 0; j <= i; j++)
            {
                sum[i][j] = max(sum[i + 1][j], sum[i + 1][j + 1]) + g[i][j];
            }
        }
        printf("%d\n", sum[0][0]);
    }
}
