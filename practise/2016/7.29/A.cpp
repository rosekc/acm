#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1

const int maxn = 5000 + 20;
int sum[maxn << 2];
int x[maxn];
void PushUp(int rt)
{
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];//更新rt节点
}
void built(int l, int r, int rt)
{
    sum[rt] = 0;
    if (l == r)
    {
        return;
    }
    int m = (l + r) >> 1;
    built(lson);
    built(rson);
}
void update(int &p, int l, int r, int rt)
{

    if (p == l && p == r)
    {
        sum[rt]++;
        return;
    }
    int m = (l + r) >> 1;
    if (p <= m) update(p, lson);
    if (p > m) update(p, rson);
    PushUp(rt);
}
int query(int &L, int R, int l, int r, int rt)
{
    if(L <= l && R >= r)
    {
        return sum[rt];
    }
    int m = (l + r) >> 1;
    int ret = 0;
    if(m >= L) ret += query(L, R, lson);
    if(m < R) ret += query(L, R, rson);
    return ret;
}

int main()
{
    int n;

    while (scanf("%d", &n) != EOF)
    {
        built(0, n - 1, 1);
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &x[i]);
            sum += query(x[i], n - 1, 0, n - 1, 1);
            update(x[i], 0, n - 1, 1);
        }
        int ret = sum;
        for(int i = 0; i < n; i++)
        {
            sum += n - x[i] - x[i] - 1;
            ret = min(ret, sum);
        }
        printf("%d\n", ret);
    }
}
