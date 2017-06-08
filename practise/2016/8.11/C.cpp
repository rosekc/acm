#include <cstdio>
#include <algorithm>
#include <cstring>
#define INF 0x3f3f3f3f
using namespace std;

const int maxn = 1000 + 10;
int a[maxn];
int dp[maxn][maxn];
int val[maxn];
int n, k;
int f(int i, int j)
{
    if (dp[i][j]) return dp[i][j];
    if (j == 0) return dp[i][j] = 0;
    if (i > 2 * j) return dp[i][j] = INF;
    return dp[i][j] = min(f(i - 1, j), f(i - 2, j - 1) + val[i - 1]);
}
void getval()
{
    for (int i = 1; i < n; i++)
    {
        val[i] = (a[i + 1] - a[i]) * (a[i + 1] - a[i]);
    }
}
int main()
{
    while (scanf("%d%d", &n, &k) != EOF)
    {
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
        }
        sort(a + 1, a + n + 1);
        memset(dp, 0, sizeof(dp));
        getval();
        printf("%d\n", f(n, k));
    }
}
