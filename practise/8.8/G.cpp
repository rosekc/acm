#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
const int maxn = 50000 + 20;
int sum[maxn << 2];
int sum1[maxn << 2];
void PushUp(int rt)
{
    sum[rt] = max(sum[rt << 1], sum[rt << 1 | 1]);//更新rt节点
    sum1[rt] = min(sum1[rt << 1], sum1[rt << 1 | 1]);
}
void built(int l, int r, int rt)
{
    if (l == r)
    {
        int t;
        scanf("%d", &t);
        sum[rt] = t;
        sum1[rt] = t;
        return;
    }
    int m = (l + r) >> 1;
    built(lson);
    built(rson);
    PushUp(rt);
}
int querymax(int L, int R, int l, int r, int rt)
{
    if(L <= l && r <= R)
    {
        return sum[rt];
    }
    int m = (l + r) >> 1;
    int ret = 0;
    if (L <= m) ret = max(querymax(L, R, lson), ret);
    if(R > m) ret = max(querymax(L, R, rson), ret);
    return ret;
}
int querymin(int L, int R, int l, int r, int rt)
{
    if(L <= l && r <= R)
    {
        return sum1[rt];
    }
    int m = (l + r) >> 1;
    int ret = 0x3f3f3f3f;
    if (L <= m) ret = min(querymin(L, R, lson), ret);
    if(R > m) ret = min(querymin(L, R, rson), ret);
    return ret;
}


int main()
{
    int n, q;
    while (scanf("%d%d", &n, &q) != EOF)
    {
        built(1, n, 1);
        for (int i = 0; i < q; i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            printf("%d\n", querymax(x, y, 1, n, 1) - querymin(x, y, 1, n, 1));
        }
    }
}
