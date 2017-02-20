#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[105][105];
int maxn[105][105];
int main()
{
    int n, t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j <= i; j++)
            {
                scanf("%d", &dp[i][j]);
            }
        if (n == 1)
        {
            printf("%d\n", dp[0][0]);
            continue;
        }
        for (int i = 0; i <= n - 2; i++)
        {
            maxn[n - 2][i] = max(dp[n - 1][i], dp[n - 1][i + 1]) + dp[n - 2][i];
        }
        for (int i = n - 3; i >= 0; i--)
            for (int j = i; j >= 0 ; j--)
            {
                maxn[i][j] = max(maxn[i + 1][j], maxn[i + 1][j + 1]) + dp[i][j];
            }

        printf("%d\n", maxn[0][0]);
    }
}
