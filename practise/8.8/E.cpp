#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1000 + 10;
int dp[maxn][maxn];
int l[45];

double getarea(int a, int b, int c)
{
    double p = 0.5 * (a + b + c);
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

bool check(int a, int b, int c)
{
    return 2 * max(a, max(b, c)) < a + b + c;
}

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        double ret = 0;
        int sum = 0;
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &l[i]);
            sum += l[i];
        }

        dp[0][0] = 1;

        for (int k = 0; k < n; k++)
        {
            for (int i = sum / 2; i >= 0; i--)
            {
                for (int j = i; j >= 0; j--)
                {
                    if (dp[i][j]) dp[i][j + l[k]] = dp[i + l[k]][j] = 1;
                }
            }
        }
        for (int i = sum / 2; i > 0; i--)
        {
            for (int j = i; j > 0; j--)
            {
                if (dp[i][j] && check(i, j, sum - i - j))
                {
                    double t = getarea(i, j, sum - i - j);
                    if(t > ret) ret = t;
                }
            }
        }
        if (ret == 0) printf("-1\n");
        else printf("%d\n", int(ret * 100));
    }
}
