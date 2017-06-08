#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1

const int maxn = 100000 + 20;
long long col[maxn << 2];
long long sum[maxn << 2];
void PushUp(int rt)
{
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];//更新rt节点
}
void PushDown(int rt, int m)
{
    if (col[rt])
    {
        col[rt << 1] += col[rt];
        col[rt << 1 | 1] += col[rt];
        sum[rt << 1] += (m - (m >> 1)) * col[rt];
        sum[rt << 1 | 1] += (m >> 1) * col[rt];
        col[rt] = 0;
    }
}
void built(int l, int r, int rt)
{
    col[rt] = 0;
    if (l == r)
    {
        scanf("%I64d", &sum[rt]);
        return;
    }
    int m = (l + r) >> 1;
    built(lson);
    built(rson);
    PushUp(rt);
}
void update(int &L, int &R, int &c, int l, int r, int rt)
{

    if (L <= l && r <= R)
    {
        col[rt] += c;
        sum[rt] += (long long)(c) * (r - l + 1);
        return;
    }
    PushDown(rt, r - l + 1);
    int m = (l + r) >> 1;
    if (L <= m) update(L, R, c, lson);
    if (R > m) update(L, R, c, rson);
    PushUp(rt);
}
long long query(int &L, int &R, int l, int r, int rt)
{
    if(L <= l && R >= r)
    {
        return sum[rt];
    }
    PushDown(rt, r - l + 1);
    int m = (l + r) >> 1;
    long long ret = 0;
    if(m >= L) ret += query(L, R, lson);
    if(m < R) ret += query(L, R, rson);
    return ret;
}

int main()
{
    int n;
    int q;
    char str[3];

    while (scanf("%d%d", &n, &q) != EOF)
    {
        built(1, n, 1);
        while (q--)
        {
            int a, b, c;
            scanf("%s%d%d", str, &a, &b);
            if (str[0] == 'Q')
            {
                printf("%I64d\n", query(a, b, 1, n, 1));
            }
            else
            {
                scanf("%d", &c);
                update(a, b, c, 1, n, 1);
            }
        }
    }
}
