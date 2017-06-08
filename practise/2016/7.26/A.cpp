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
    int t, i, j;
    int con = 1;
    char str[8];

    scanf("%d", &t);

    while (t--)
    {
        scanf("%d", &n);
        memset(a, 0, sizeof(a));
        //for(int k = 0; k < 2000000000; k++) printf("%d\n", a[k]);
        for (int k = 1; k <= n; k++)
        {
            int tmp;
            scanf("%d", &tmp);
            add(k, tmp);
        }
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
                printf("%d\n", cal(j) - cal(i - 1));
            }
            else if (strcmp(str, "Add") == 0)
            {
                add(i, j);
            }
            else if (strcmp(str, "Sub") == 0)
            {
                add(i, -j);
            }
        }
    }
}
