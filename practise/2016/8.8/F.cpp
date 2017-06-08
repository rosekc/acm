#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

const int maxk = 100 + 10;
int dp[maxk];
struct gang
{
    int t, p, s;
};
bool cmp(gang a, gang b)
{
    return a.t < b.t;
}
gang data[maxk];

int main()
{
    int n, k, tt;
    while (scanf("%d%d%d", &n, &k, &tt) != EOF)
    {
        int ans = 0;
        data[0] = {0, 0, 0};
        for (int i = 1; i <= n; i++) scanf("%d", &data[i].t);
        for (int i = 1; i <= n; i++) scanf("%d", &data[i].p);
        for (int i = 1; i <= n; i++) scanf("%d", &data[i].s);
        memset(dp, -1, sizeof(dp));
        dp[0] = 0;
        sort(data + 1, data + n + 1, cmp);
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (dp[j] != -1 && abs(data[j].s - data[i].s) <= data[i].t - data[j].t)
                {
                    dp[i] = max(dp[i], dp[j] + data[i].p);
                    ans = max(ans, dp[i]);
                }
            }
        }
        printf("%d\n", ans);
    }
}
