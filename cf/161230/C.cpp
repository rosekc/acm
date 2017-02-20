//2016-12-30-23.12
//C

#include <cstdio>
using namespace std;

int main()
{
    int n, c, d;
    while (scanf("%d", &n) != EOF)
    {
        int cur = 0;
        int min1 = 0x3f3f3f3f;
        int max2 = -0x3f3f3f3f;
        bool f = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d", &c, &d);
            if (d == 1 && cur <= max2) f = 1;
            if (d == 2 && cur >= min1) f = 1;
            if (d == 2 && cur > max2) max2 = cur;
            if (d == 1 && cur < min1) min1 = cur;
            if (f) continue;
            cur += c;
            //printf("%d\n", cur);
        }
        if (max2 == -0x3f3f3f3f) puts("Infinity");
        else if (f) puts("Impossible");
        else
        {
            printf("%d\n", 1899 - max2 + cur);
        }
    }
}
