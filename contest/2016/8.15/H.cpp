#include <cstdio>
#define lson l, m,rt << 1
#define rson m + 1, r, rt << 1 | 1

const int maxn = 50000 + 20;
int sum[maxn << 2];
int col[maxn << 2];
void pushup(int rt)
{
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}
void pushdown(int rt, int m)
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
        col[rt] += c;
        sum[rt] += c * (r - l + 1);
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
            //printf("%d %d\n", a, b);
            if (a == 1)
            {
                if ((n - query(1, n, 1, n, 1)) < b)
                {
                    //printf("%d %d\n", n - query(1, n, 1, n, 1), b);
                    printf("0\n");
                    continue;
                }
                for (int i = 1; i <= n - b + 1; i++)
                {
                    //printf("     %d\n", query(i, i + b - 1, 1, n, 1));
                    if(query(i, i + b - 1, 1, n, 1) == 0)
                    {
                        update(i, i + b - 1, 1, 1, n, 1);
                        //printf("     %d\n", query(i, i + b - 1, 1, n, 1));
                        printf("%d\n", i);
                        break;
                    }
                    //printf("     %d\n", query(i, i + b - 1, 1, n, 1));
                    if (i == n - b + 1) printf("0\n");
                }
            }
            else
            {
                scanf("%d", &a);
                update(b, b + a - 1, -1, 1, n, 1);
            }
        }
    }
}
