//2017-01-21-19.23
//1002

#include <bits/stdc++.h>
using namespace std;

struct node
{
    int c;
    double i;
    bool operator < (const node & b)const
    {
        return i < b.i;
    }
};
node d[50000 * 2 + 100];
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        int l, r, a, b, c;
        long long st = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d%d%d%d", &l, &r, &a, &b, &c);
            d[i * 2].i = l;
            d[i * 2 + 1].i = r + .5;
            d[i * 2].c = a - c;
            d[i * 2 + 1].c = b - a;
            st += c;
        }
        sort(d, d + (2 * n));
        long long mx = -1;
        int cur = 0;
        for (int i = 0; i < 2 * n; i++)
        {
            //printf("%f %d\n", d[i].i, d[i].c);
            if (d[i].i != cur)
            {
                if (mx < st) mx = st;
                cur = d[i].i;
            }
            st += d[i].c;
            //printf("  %d\n", st);
        }
        printf("%I64d\n", mx);
    }
}
