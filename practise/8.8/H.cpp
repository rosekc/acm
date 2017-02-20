#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 100 + 5;
int dp[maxn][maxn];
char s1[maxn], s2[maxn];
int val[5][5] = {5, -1, -2, -1, -3,
                 -1, 5, -3, -2, -4,
                 -2, -3, 5, -2, -2,
                 -1, -2, -2, 5, -1,
                 -3, -4, -2, -1, 0};
int chlist(char i)
{
    if(i == 'A') return 0;
    if(i == 'C') return 1;
    if(i == 'G') return 2;
    if(i == 'T') return 3;
    if(i == '-') return 4;
}
int f(int i, int j)
{
    if (dp[i][j] != 0x3f3f3f3f) return dp[i][j];
    if (!i && !j) return dp[i][j] = 0;
    if (i == 0) return dp[i][j] = f(i, j - 1) + val[chlist('-')][chlist(s2[j - 1])];
    if (j == 0) return dp[i][j] = f(i - 1, j) + val[chlist(s1[i - 1])][chlist('-')];
    return dp[i][j] = max(f(i - 1, j - 1) + val[chlist(s1[i - 1])][chlist(s2[j - 1])],
                      max(f(i, j - 1) + val[chlist('-')][chlist(s2[j - 1])],
                          f(i - 1, j) + val[chlist(s1[i - 1])][chlist('-')]));
}
int main()
{
    int t, n, m;
    scanf("%d", &t);
    while (t--)
    {
        memset(dp, 0x3f, sizeof(dp));
        scanf("%d%s%d%s", &n, s1, &m, s2);
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                f(i, j);
            }
        }
        printf("%d\n", dp[n][m]);
    }
}
