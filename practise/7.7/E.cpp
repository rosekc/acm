#include <cstdio>
#include <algorithm>
using namespace std;

struct stick
{
    int l;
    int w;
    bool s;
};

bool cmp(const stick &a, const stick &b)
{
    if (a.l == b.l)
    {
        return a.w < b.w;
    }
    else return a.l < b.l;
}
stick d[5000 + 5];
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        if (n == 0)
        {
            printf("0\n");
            continue;
        }
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d", &d[i].l, &d[i].w);
            d[i].s = 1;
        }
        sort(d, d + n, cmp);
        int ind = 1;
        int inw = d[0].w;
        int inl = d[0].l;
        int con = 1;
        int ret = 1;
        while (1)
        {
            if (d[ind].s && d[ind].w >= inw && d[ind].l >= inl)
            {
                inw = d[ind].w;
                inl = d[ind].l;
                d[ind].s = 0;
                con++;
            }
            //printf("%d\n", con);
            if (con == n) break;
            if (++ind == n)
            {
                inw = 0;
                inl = 0;
                ind = 1;
                ret++;
            }
        }
        printf("%d\n", ret);
    }
}
