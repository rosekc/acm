//2016-10-18-22.24
//UVa1225

#include <cstdio>
#include <cstring>
using namespace std;

long long re[10];
int main()
{
    int n, t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        memset(re, 0, sizeof(re));
        for (int i = 1; i <= n; i++)
        {
            int t = i;
            while (t >= 10)
            {
                re[t % 10]++;
                t /= 10;
            }
            re[t]++;
        }
        for (int i = 0;; i++)
        {
            printf("%lld", re[i]);
            if (i != 9) printf(" ");
            else break;
        }
        printf("\n");
    }
}
