#include <cstdio>
#include <cstring>
using namespace std;
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
const int maxn = 100000 + 20;
int sum[maxn << 2];
int n = maxn;
void PushUp(int rt)
{
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}
void built(int l, int r, int rt)
{
    if (l == r)
    {
        sum[rt] = 0;
        return;
    }
    int m = (l + r) >> 1;
    built(lson);
    built(rson);
    PushUp(rt);
}
void update(int p, int add, int l, int r, int rt)
{
    if (l == r)
    {
        sum[rt] += add;
        return;
    }
    int m = (l + r) >> 1;
    if (p <= m) update(p, add, lson);
    else update(p, add, rson);
    PushUp(rt);
}
int query(int L, int R, int l, int r, int rt)
{
    if (L <= l && r <= R)
    {
        return sum[rt];
    }
    int m = (l + r) >> 1;
    int ret = 0;
    if (L <= m) ret += query(L, R, lson);
    if (R > m) ret += query(L, R, rson);
    return ret;
}

int main()
{
    int m;
    int nn;
    scanf("%d", &nn);
    built(1, n, 1);
    for (int i = 0; i < nn; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        update(tmp, 1, 1, n, 1);
    }
    scanf("%d", &m);
    while (m--)
    {
        int t;
        scanf("%d", &t);
        printf("%d\n", query(1, t, 1, n, 1));
    }
}
