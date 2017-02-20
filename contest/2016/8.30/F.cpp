#include <cstdio>
#include <algorithm>
using namespace std;

int d[100000];
int n;
int stswap(int i)
{
    if (i > n - 1) return i - 2;
    if (d[i] > d[i + 1])
    {
        //puts("123");
        swap(d[i], d[i + 1]);
        return stswap(i + 2);
    }
    return i - 2;
}
int main()
{
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &d[i]);
        }
        while (1)
        {
            bool flag = 1;
            int st, ed;
            for (int i = 1; i <= n - 1; i++)
            {
                int tmp = stswap(i);
                //printf("%d\n", tmp);
                if (tmp + 1 > i)
                {
                    flag = 0;
                    printf("%d %d\n", i, tmp + 1);
                    break;
                }
            }
            if (flag) break;
        }
    }
}
