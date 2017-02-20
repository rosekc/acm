#include <cstdio>
#include <cstring>

using namespace std;

#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
const int maxn = 100000 + 10;
int M;
int sum[maxn << 2];
void PushUp(int rt)
{
    sum[rt] = ((long long)sum[rt << 1] * sum[rt << 1 | 1]) % M;
}
void built(int l, int r, int rt)
{
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
void update(int p, int chg, int l, int r, int rt)
{
    if (l == r)
    {
        sum[rt] = chg;
        return;
    }
    int m = (l + r) >> 1;
    if (p <= m) update(p, chg, lson);
    else update(p, chg, rson);
    PushUp(rt);
}


int main()
{
    int con = 1;
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d%d", &n, &M);
        built(1, n, 1);
        printf("Case #%d:\n", con++);
        for (int i = 1; i <= n; i++)
        {
            int j, k;
            scanf("%d%d", &j, &k);
            if (j == 2)
            {
                update(k, 1, 1, n, 1);
            }
            else
            {
                update(i, k, 1, n, 1);
            }
            printf("%I64d\n", sum[1]);
        }
    }
}
