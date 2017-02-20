#include <cstdio>
#include <algorithm>

using namespace std;

#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
const int maxn = 1000 + 10;
int sum[maxn << 2];
void PushUp(int rt)
{
    sum[rt] = max(sum[rt << 1], sum[rt << 1 | 1]);
}
void built(int l, int r, int rt)
{
    if (l == r)
    {
        scanf("%d", &sum[rt]);
        return;
    }
    int m = (l + r) >> 1;
    built(lson);
    built(rson);
    PushUp(rt);
}

int query(int L, int R, int l, int r, int rt)
{
    if(L <= l && r <= R)
    {
        return sum[rt];
    }
    int m = (l + r) >> 1;
    int ret = 0;
    if (L <= m) ret = max(query(L, R, lson), ret);
    if (R > m) ret = max(query(L, R, rson), ret);
    return ret;
}

int main()
{
    int t, n, q;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        built(1, n, 1);
        scanf("%d", &q);
        while (q--)
        {
            int i, j;
            scanf("%d%d", &i, &j);
            printf("%d\n", query(i, j, 1, n, 1));
        }
    }
}
