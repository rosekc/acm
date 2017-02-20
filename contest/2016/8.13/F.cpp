#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

double dp[30];
int a[4];
bool b[];

int main()
{
    int q, n;
    while (scanf("%d%d", &q, &n) != EOF && n)
    {
        for (int i = 1; i <= n; i++)
        {
            int tn;
            char tc[2];
            double tmp;
            double sum = 0;
            scanf("%d", &tn);
            while (tn--)
            {
                scnaf("%s:%f", &tc, &tmp)
                if (tc[0] != 'A' || tc[0] != 'B' || tc[0] != 'C') b[i] = 1;
                if (tmp > 600) b[i] = 1;
                sum += tmp;
            }
            if (sum > 1000) b[i] = 1;
            a[i] = sum;
        }

        memset(dp, 0, sizeof(dp));
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            if (b[i])
            {
                dp[i] = dp[i - 1];
                continue;
            }
            dp[i] = max()
        }
        printf("%d\n", dp[n]);
    }
}
