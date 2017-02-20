#include <cstdio>
#include <cstring>

const int maxn = 10 + 5;
int dp[maxn][maxn];

int f(int i, int j)
{
    if (dp[i][j] != -1) return dp[i][j];
    if (i == 1 || j == 1) return dp[i][j] = 1;
    if (i < j) return dp[i][j] = f(i, i);
    if (i == j) return dp[i][j] = f(i, j - 1) + 1;
    if (i > j) return  dp[i][j] = f(i, j - 1) + f(i - j, j);
}

int main()
{
    int t, i, j;
    scanf("%d", &t);
    memset(dp, -1, sizeof(dp));
    while (t--)
    {
        scanf("%d%d", &i, &j);
        printf("%d\n", f(i, j));
    }
}
