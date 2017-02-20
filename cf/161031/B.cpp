//2016-10-31-22.30
//B

#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    while (scanf("%d", &t) != EOF)
    {
        int maxn = -0x3f3f3f3f, minn = 0x3f3f3f3f, t1, t2, sum = 0;
        int mx, mn;
        bool f1 = 0, f2 = 0;
        for (int i = 1; i <= t; i++)
        {
            scanf("%d%d", &t1, &t2);
            int tmp = t1 - t2;
            sum += (tmp);
            if (tmp > 0 && maxn < tmp)
            {
                f1 = 1;
                mx = i;
                maxn = tmp;
            }
            if (tmp < 0 && minn > tmp)
            {
                f2 = 1;
                mn = i;
                minn = tmp;
            }
        }
        int ans;
        minn *= 2;
        maxn *= 2;
        if (f1 && f2)
        {
            //printf("%d %d %d\n", abs(sum), abs(sum - minn), abs(sum - maxn));
            //printf("%d %d\n", mx, mn);
            if (abs(sum) < abs(sum - minn) || abs(sum) < abs(sum - maxn))
            {
                int tmp = abs(sum - minn) - abs(sum - maxn);
                if (tmp > 0) ans = mn;
                else if (tmp < 0) ans = mx;
                else ans = mx;
            }
            else ans = 0;
        }
        else ans = 0;
        printf("%d\n", ans);
    }
}
