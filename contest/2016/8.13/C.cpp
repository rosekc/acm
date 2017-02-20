#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[10005];
int a[4] = {0, 150, 200, 350};

int main()
{
    int t, n;
    scanf("%d", &t);
    while (t--)
    {
        memset(dp, 0, sizeof(dp));
        scanf("%d", &n);
        for (int i = 1; i <= 3; i++)
        {
            for (int v = a[i]; v <= n; v++)
            {
                dp[v] = max(dp[v], dp[v - a[i]] + a[i]);
            }
        }
        printf("%d\n", n - dp[n]);
    }
}
