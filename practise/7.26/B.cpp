#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 200000 + 20;
int n;
int a[maxn];
int lowbit(int x)
{
    return x & (-x);
}
int cal(int t)//计算1-t的和
{
    int sum = 0;
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
        //printf("123");
    }
}

int main()
{
    int i, j;

    while (scanf("%d", &n) != EOF && n != 0)
    {
        memset(a, 0, sizeof(int) * (n + 1));
        //for(int k = 0; k < 2000000000; k++) printf("%d\n", a[k]);
        for (int k = 1; k <= n; k++)
        {
            scanf("%d%d", &i, &j);
            add(i, 1);
            add(j + 1, -1);
        }
        for (int k = 1; k <= n; k++)
        {
            printf("%d", cal(k));
            if(k != n) printf(" ");
        }
        printf("\n");
    }
}
