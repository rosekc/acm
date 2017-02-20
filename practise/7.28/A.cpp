#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1

const int maxn = 100000 + 20;
int col[maxn << 2];
int sum[maxn << 2];
void PushUp(int rt)
{
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];//更新rt节点
}
void PushDown(int rt, int m)
{
    if (col[rt])
    {
        col[rt << 1] = col[rt << 1 | 1] = col[rt];
        sum[rt << 1] = (m - (m >> 1)) * col[rt];
        sum[rt << 1 | 1] = (m >> 1) * col[rt];
        col[rt] = 0;
    }
}
void built(int l, int r, int rt)
{
    col[rt] = 0;
    if (l == r)
    {
        sum[rt] = 1;
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
        col[rt] = c;
        sum[rt] = c * (r - l + 1);
        return;
    }
    PushDown(rt, r - l + 1);
    int m = (l + r) >> 1;
    if (L <= m) update(L, R, c, lson);
    if (R > m) update(L, R, c, rson);
    PushUp(rt);
}

int main()
{
    int t;
    int n;
    int u;
    int con = 1;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &u);
        built(1, n, 1);
        while (u--)
        {
            int a, b, c;
            scanf("%d%d%d", &a,&b, &c);
            update(a, b, c, 1, n, 1);
        }
        printf("Case %d: The total value of the hook is %d.\n",
                con++, sum[1]);
    }
}
