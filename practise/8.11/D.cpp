#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[100010][11];
int main()
{
    int n, t, p;
    while (scanf("%d", &n) != EOF && n)
    {
        int tmax = -1;
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++)
        {
            scanf("%d%d", &p, &t);
            dp[t][p]++;
            tmax = max(tmax, t);
        }
        for (int i = tmax - 1; i >= 0; i--)
        {
            dp[i][0] += max(dp[i + 1][0], dp[i + 1][1]);
            dp[i][10] += max(dp[i + 1][10], dp[i + 1][9]);
            for (int j = 1; j < 10; j++)
            {
                dp[i][j] += max(dp[i + 1][j], max(dp[i + 1][j - 1], dp[i + 1][j + 1]));
            }
        }
        printf("%d\n", dp[0][5]);
    }
}
