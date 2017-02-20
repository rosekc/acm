//2016-11-26-13.56
//B

#include <cstdio>
#include <algorithm>
using namespace std;
int d[100000 + 10];
int main()
{
    int t, n;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &d[i]);
        }
        sort(d, d + n);
        bool f = 0;
        bool isfirst = 1;
        for (int i = 0;; i++)
        {
            if (i == n) break;
            if (i < n - 1 && d[i] == d[i + 1])
            {
                puts("111111");
                f = 1;
                continue;
            }
            else
            {
                if (f)
                {
                    f = 0; continue;
                }
                else
                {

                    if (isfirst) {printf("%d", d[i]); isfirst = 0;}
                    else printf(" %d", d[i]);
                }
            }
        }
    }
}
