//2016-12-10-13.45
//

#include <cstdio>
using namespace std;
const int maxn = 2000000 + 10;
bool d[maxn];
int r[maxn], rsize = 0;
bool check(int i)
{
    int t = 0;
    while (i >= 10)
    {
        t = t * 10 + i % 10;
        i /= 10;
    }
    t = t * 10 + i;
    return d[t];
}
int main()
{
    d[1] = 1;
    //puts("11");
    for (int i = 2; i < maxn; i++)
    {
        //puts("d");
        if (d[i] == 1) continue;
        //printf("%d\n", i);
        //puts("111");
        for (int j = 2;; j++)
        {
            int t = i * j;
            if (t >= maxn) break;
            d[t] = 1;
        }
    }
    for (int i = 2; i < 101000; i++)
    {
        //printf("%d %d\n", i, d[i]);
        if (d[i]) continue;

        //puts("1");
        if (check(i) == 0)
        {
            if (i < 10) continue;
            //puts("111");
            r[rsize++] = i;
        }
    }
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        printf("%d\n", r[n]);
    }
}
