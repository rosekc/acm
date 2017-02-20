#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int dp[10005];
int a[100];
int b[100];
int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        int con = 1;
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        for (int i = 1; i <= n; i++)
        {
            dp[i] = 1;
            for (int j = 1; j < i; j++)
            {
                if (a[i] <= a[j] && dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                }
            }
        }
        memset(b, 0, sizeof(b));
        for (int i = 1; i <= n; i++)
        {
            b[dp[i]]++;
            printf("%d ", dp[i]);
        }
        for (int i = 1; i <= n; i++)
        {
            con = max(con, b[i]);
        }
        printf("\n");
        printf("%d\n", con);
    }
    //printf("%d\n", s.size());
}
