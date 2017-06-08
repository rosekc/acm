#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1

const int maxn = 200000 + 20;
int sum[maxn << 2];
int h, w, n;
void PushUp(int rt)
{
    sum[rt] = max(sum[rt << 1], sum[rt << 1 | 1]);//更新rt节点
}
void built(int l, int r, int rt)
{
    if (l == r)
    {
        sum[rt] = w;
        return;
    }
    int m = (l + r) >> 1;
    built(lson);
    built(rson);
    PushUp(rt);
}
int query(int &i, int l, int r, int rt)
{
    if (i > sum[rt]) return -1;
    if (l == r)
    {
        sum[rt] -= i;
        return l;
    }
    else
    {
        int m = (l + r) >> 1;
        int ret;
        ret = query(i, lson);
        if(ret != -1)
        {
            PushUp(rt);
            return ret;
        }
        else
        {
            PushUp(rt);
            return query(i, rson);
        }
    }
}



int main()
{
    int wi;

    while (scanf("%d%d%d", &h, &w, &n) != EOF)
    {
        //for(int k = 0; k < 2000000000; k++) printf("%d\n", a[k]);
        int t = min(h, n);
        built(1, t, 1);
        //for(int k = 1; k <= n; k++) printf("%d\n", cal(k));
        while (n--)
        {
            scanf("%d", &wi);
            int q = query(wi, 1, t, 1);
            printf("%d\n", q);
        }
    }
}
