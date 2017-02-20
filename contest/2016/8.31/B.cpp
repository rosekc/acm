#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

struct data
{
    int o;
    int d;
};
bool cmp(data &a, data &b)
{
    if (a.d == b.d)
    {
        return a.o < b.o;
    }
    else return a.d < b.d;
}
data d[100000 + 100];
int main()
{
    int t, n;
    scanf("%d", &t);
    for (int con = 1; con <= t; con++)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &d[i].d);
            d[i].o = i;
        }
        sort(d + 1, d + n + 1, cmp);
        printf("Case #%d:", con);
        int j = 0;
        bool flag = (d[1 + j].o - 1) == (n - d[n + j].o);
        for (int i = 1; i <= n; i++)
        {
            if (i == 1 || i == n) printf(" %d", abs(i - d[i].o)2);
            else printf(" %d", abs(i - d[i].o) + flag);
        }
        printf("\n");
    }
}
