#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 1000 + 5;
const int maxk = 30 + 5;
int dp[maxn][maxk];
int a[maxn];
int b[maxn];
int re1[maxn];
int re2[maxn];
int n, v, k;
int getans()
{
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        for (int j = v; j >= b[i]; j--)
        {
            for (int l = 1; l <= k; l++)
            {
                re1[l] = dp[j][l];
                re2[l] = dp[j - b[i]][l] + a[i];
            }
            re1[k + 1] = re2[k + 1] = -1;
            int w = 1;
            int x = 1;
            int y = 1;
            while (w <= k&&(x<=k||y<=k))
            {
                if (re1[x] > re2[y])
                {
                    dp[j][w] = re1[x++];
                }
                else
                {
                    dp[j][w] = re2[y++];
                }
                if (w == 1 || dp[j][w] != dp[j][w - 1]) w++;
                //printf("%d\n", dp[j][w - 1]);
            }
            //printf("%d ", dp[j][k]);
        }
        //printf("\n");
    }
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d%d", &n, &v, &k);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
        getans();
        printf("%d\n", dp[v][k]);
    }
}
