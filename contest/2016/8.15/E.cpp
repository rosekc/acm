#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 20 + 5;
int a[maxn][maxn];
int dp[maxn][maxn];
int n, m;

int f(int i, int j)
{
    if (dp[i][j] != -1) return dp[i][j];
    if (i == 0 && j == 0) return dp[i][j] = a[i][j];
    if (i == 0) return dp[i][j] = f(i, j - 1) + a[i][j];
    if (j == 0) return dp[i][j] = f(i - 1, j) + a[i][j];
    return dp[i][j] = max(f(i - 1, j), f(i, j - 1)) + a[i][j];
}

int main()
{
    while (scanf("%d%d", &n, &m) != EOF)
    {
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d", &a[i][j]);
            }
        }
        printf("%d\n", f(n - 1, m - 1));
    }
}
