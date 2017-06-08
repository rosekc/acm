#include <cstdio>
#include <cstring>

using namespace std;

#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
const int maxn = 50000 + 20;
int sum[maxn << 2];
void PushUp(int rt)
{
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];//更新rt节点
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
void update(int p, int add, int l, int r, int rt)  //在p节点加上add
{
    if (l == r)
    {
        sum[rt] = add;
        return;
    }
    int m = (l + r) >> 1;
    if (p <= m) update(p, add, lson);
    else update(p, add, rson);
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
    if (L <= m) ret += query(L, R, lson);
    if(R > m) ret += query(L, R, rson);
    return ret;
}



int main()
{
    int t, i, j, n;
    int con = 1;
    char str[8];

    scanf("%d", &t);

    while (t--)
    {
        scanf("%d", &n);
        //for(int k = 0; k < 2000000000; k++) printf("%d\n", a[k]);
        built(1, n, 1);
        printf("Case %d:\n", con++);
        //for(int k = 1; k <= n; k++) printf("%d\n", cal(k));
        while (1)
        {
            scanf("%s", str);
            if (strcmp(str, "End") == 0)
            {
                break;
            }
            scanf("%d %d", &i, &j);
            //printf("%s\n", str);
            if (strcmp(str, "Query") == 0)
            {
                printf("%d\n", query(i, j, 1, n, 1));
            }
            else if (strcmp(str, "Add") == 0)
            {
                update(i, j, 1, n, 1);
            }
            else if (strcmp(str, "Sub") == 0)
            {
                update(i, -j, 1, n, 1);
            }
        }
    }
}
