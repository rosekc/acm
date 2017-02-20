#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1

const int maxn = 50000 + 20;
int col[maxn << 2];
int sum[maxn << 2];
void pushup(int rt)
{
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}
void pushdown(int rt, int m)
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
        sum[rt] = 0;
        return;
    }
    int m = (l + r) >> 1;
    built(lson);
    built(rson);
    pushup(rt);
}
void update(int L, int R, int c, int l, int r, int rt)
{
    if (L <= l && r <= R)
    {
        col[rt] = c;
        sum[rt] = c * (r - l + 1);
        return;
    }
    pushdown(rt, r - l + 1);
    int m = (l + r) >> 1;
    if (L <= m) update(L, R, c, lson);
    if (R > m) update(L, R, c, rson);
    pushup(rt);
}
int query(int L, int R, int l, int r, int rt)
{
    if (L <= l && R >= r)
    {
        return sum[rt];
    }
    pushdown(rt, r - l + 1);
    int m = (l + r) >> 1;
    int ret = 0;
    if (m >= L) ret += query(L, R, lson);
    if (m < R) ret += query(L, R, rson);
    return ret;
}
int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        built(1, n, 1);
        while (m--)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            //printf("   %d\n", m);
            if (a == 1)
            {
                if (n - sum[1] < b)
                {
                    printf("0\n");
                    continue;
                }
                for (int i = 1; i <= n - b + 1; i++)
                {
                    //printf("q%d %d:%d\n", i, i + b - 1, query(i, i + b - 1, 1, n, 1));
                    if (query(i, i + b - 1, 1, n, 1) == 0)
                    {
                        printf("%d\n", i);
                        update(i, i + b - 1, 1, 1, n, 1);
                        break;
                    }
                    if (i == n - b + 1) printf("0\n");
                }
            }
            else
            {
                scanf("%d", &a);
                update(b, b + a - 1, 0, 1, n, 1);
            }
        }
    }
}
