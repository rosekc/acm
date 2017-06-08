#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 200000 + 20;
int n = 15005;
int a[maxn];
int level[maxn];
int lowbit(int x)
{
    return x & (-x);
}
int cal(int t)//计算1-t的和
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
void add(int x, int v) //在x的位置加上v
{
    while (x <= n)
    {
        a[x] += v;
        x += lowbit(x);
        //printf("123\n");
    }
}

int main()
{
    int x;
    int t;

    while (scanf("%d", &t) != EOF && t != 0)
    {
        memset(a, 0, sizeof(a));
        memset(level, 0, sizeof(int) * (n + 1));
        //for(int k = 0; k < 200; k++) printf("%d\n", a[k]);
        for (int k = 1; k <= t; k++)
        {
            scanf("%d%*d", &x);
            //printf("%d\n", x);
            x++;
            //printf("%d\n", cal(x));
            level[cal(x)]++;
            add(x, 1);
        }
        for (int k = 0; k < t; k++)
        {
            printf("%d\n", level[k]);
            //if(k != n) printf(" ");
        }
        //printf("\n");
    }
}
