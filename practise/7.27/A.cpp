#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
const int maxn = 200000 + 20;
int sum[maxn << 2];
void PushUp(int rt)
{
    sum[rt] = max(sum[rt << 1], sum[rt << 1 | 1]);//更新rt节点
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
int query(int L, int R, int l, int r, int rt)
{
    if(L <= l && r <= R)
    {
        return sum[rt];
    }
    int m = (l + r) >> 1;
    int ret = 0;
    if (L <= m) ret = max(query(L, R, lson), ret);
    if(R > m) ret = max(query(L, R, rson), ret);
    //printf("%d ", ret);
    return ret;
}



int main()
{
    int q, i, j, n;
    int con = 1;
    char str[3];



    while (scanf("%d%d", &n, &q) != EOF)
    {
        //for(int k = 0; k < 2000000000; k++) printf("%d\n", a[k]);
        built(1, n, 1);
        //for(int k = 1; k <= n; k++) printf("%d\n", cal(k));
        while (q--)
        {
            scanf("%s", str);

            scanf("%d %d", &i, &j);
            //printf("%s\n", str);
            if (str[0] == 'Q')
            {
                printf("%d\n", query(i, j, 1, n, 1));
            }
            else if (str[0] == 'U')
            {
                update(i, j, 1, n, 1);
            }
        }
    }
}
