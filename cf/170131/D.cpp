//2017-02-01-00.04
//

#include <bits/stdc++.h>
using namespace std;

struct node
{
    int a, b, c, p, i;
    bool operator < (const node &b)const
    {
        return p < b.p;
    }
};
bool cmp(node a, node b)
{
    return a.i< b.i;
}
node d[1000000 + 10];
int main()
{
    int n, l, r;
    scanf("%d%d%d", &n, &l, &r);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &d[i].a);
        d[i].i = i;
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &d[i].p);
    }
    sort(d, d + n);
    d[0].b = l;
    d[0].c = d[0].b - d[0].a;
    for (int i = 1; i < n; i++)
    {
        d[i].c = d[i - 1].c + 1;
        d[i].b = d[i].a + d[i].c;
        while (d[i].b < l) {d[i].b++; d[i].c++;}
        //printf("%d\n", d[i].b);
        if (d[i].b > r || d[i].c > r)
        {
            printf("-1\n");
            return 0;
        }
    }
    sort(d, d + n, cmp);
    bool isfirst = 1;
    for (int i = 0; i < n; i++)
    {
        if (isfirst) {printf("%d", d[i].b); isfirst = 0;}
        else printf(" %d", d[i].b);
    }
    puts("");
}
