#include <cstdio>
#include <algorithm>
using namespace std;
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1

const int maxn = 2000 + 50;
long long sum[maxn << 2];
void pushup(int rt)
{
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}
void built(int l, int r, int rt)
{
    if (l == r)
    {
        scanf("%lld", &sum[rt]);
        return;
    }
    int m = (l + r) >> 1;
    built(lson);
    built(rson);
    pushup(rt);
}
long long query(int L, int R, int l, int r, int rt)
{
    if (L <= l && R >= r)
    {
        return sum[rt];
    }
    int m = (l + r) >> 1;
    long long ret = 0;
    if (m >= L) ret += query(L, R, lson);
    if (m < R) ret += query(L, R, rson);
    return ret;
}
int main()
{
    int t, m, n;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &m);
        long long ret = 0;
        built(1, n, 1);
        for (int j = m; j <= n; j++)
        {
            for (int i = 1; i <= n - j + 2; i++)
            {
                ret = max(query(i, i + j - 1, 1, n, 1) * 1000 / j, ret);
            }
        }

        printf("%lld\n", ret);
    }
}
