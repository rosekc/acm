#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

struct Point
{
    int x;
    int y;
    int num;
};

const int maxn = 100000 + 20;
int n = maxn;
Point data[maxn];
int a[maxn];
int level[maxn];
int lowbit(int x)
{
    return x & (-x);
}
int cal(int t)//计算1-t的和
{
    int sum = 0;
    if (t == 1) return a[t];
    while (t > 0)
    {
        sum += a[t];
        t -= lowbit(t);
    }
    return sum;
}
void add(int x) //在x的位置加上v
{
    while (x <= n)
    {
        a[x] += 1;
        x += lowbit(x);
        //printf("123\n");
    }
}

bool cmp1(Point a, Point b)
{
    if (a.y == b.y)
    {
        return a.x < b.x;
    }
    return a.y > b.y;
}

int main()
{
    int tx = -1, ty = -1, tl = -1;
    int t;

    while (scanf("%d", &t) != EOF && t)
    {
        memset(a, 0, sizeof(a));
        //memset(level, 0, sizeof(level));
        //for(int k = 0; k < 200; k++) printf("%d\n", a[k]);
        for (int k = 0; k < t; k++)
        {
            scanf("%d%d", &data[k].x, &data[k].y);
            data[k].num = k;
            //printf("%d\n", x);
            data[k].x++;
            data[k].y++;
            //printf("%d\n", cal(x));
        }
        sort(data, data + t, cmp1);
        for (int k = 0; k < t; k++)
        {
            //printf("%d\n", cal(x));
            if (tx == data[k].x && ty == data[k].y)
            {
                level[data[k].num] = tl;
            }
            else
            {
                level[data[k].num] = cal(data[k].x);
                tx = data[k].x;
                ty = data[k].y;
                tl = level[data[k].num];
            }
            add(data[k].x);
        }
        for (int k = 0; k < t; k++)
        {
            printf("%d", level[k]);
            if (k != n) printf(" ");
        }
        printf("\n");
    }
}
