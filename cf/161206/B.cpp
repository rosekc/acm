//2016-12-06-22.47
//B

#include <cstdio>
#include <cstring>
using namespace std;
int d[200000 + 20];
int main()
{
    int n, x;
    while (scanf("%d%d", &n, &x) != EOF)
    {
        long long con = 0;
        int in;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &in);
            d[in]++;
        }
        if (n == 1)
        {
            puts("0");
            continue;
        }
        for (int i = 0; i <= 100000; i++)
        {
            if (d[i] != 0)
            {
                int t = x ^ i;
                //printf("%d %d\n", i, t);
                if (t > 0 && t <= 100000)
                {
                    if (t != i) con += ((long long)d[i] * (long long)d[t]);
                    else con += ((long long)d[i] * ((long long)d[t] - 1));
                }
                //puts("111");
            }
        }
        printf("%I64d\n", con / 2);
    }
}
