#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 100000 + 5;
int n;
int m;
int a[maxn];
int b[maxn];
int c[maxn];
int d[maxn];
int lowbit(int x)
{
    return x & (-x);
}
int cal(int t, int a[])//计算1-t的和
{
    int sum = 0;
    if(t == 1) return a[t];
    while (t > 0)
    {
        sum += a[t];
        t -= lowbit(t);
    }
    return sum;
}
void add(int x, int &n, int a[]) //在x的位置加上v
{
    while (x <= n)
    {
        a[x]++;
        x += lowbit(x);
        //printf("123\n");
    }
}

int main()
{
    int x, y;
    int x1, y1;
    int t;
    int k, q;

    scanf("%d", &t);

    while (t--)
    {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(c, 0, sizeof(c));
        memset(d, 0, sizeof(d));
        scanf("%d%d%d%d", &n, &m, &k, &q);
        //for(int k = 0; k < 200; k++) printf("%d\n", a[k]);
        for (int i = 1; i <= k; i++)
        {
            scanf("%d%d", &x, &y);
            if(c[x] == 0)
            {
                add(x, n, a);
                c[x] = 1;
            }
            if(d[y] == 0)
            {
                add(y, m, b);
                d[y] = 1;
            }
        }
        for (int i = 1; i <= q; i++)
        {
            scanf("%d%d%d%d", &x, &y, &x1, &y1);
            //printf("%d %d\n", cal(y1, b) - cal(y - 1, b), y1 - y + 1);
            if(cal(x1, a) - cal(x - 1, a) == (x1 - x + 1) || cal(y1, b) - cal(y - 1, b) == (y1 - y + 1))
            {
                printf("Yes\n");
            }
            else
            {
                printf("No\n");
            }
        }
        //printf("\n");
    }
}
