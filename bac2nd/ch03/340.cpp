//2016-09-27-22.37
//UVa 340

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1010;
int a[maxn], b[maxn];
int c1[10], c2[10];
int main()
{
    int n;
    int con = 1;
    while (scanf("%d", &n) != EOF && n != 0)
    {
        memset(c1, 0, sizeof(c1));
        printf("Game %d:\n", con++);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            c1[a[i]]++;
        }
        for (;;)
        {
            memset(c2, 0, sizeof(c2));
            bool flag = 1;
            int a1 = 0, b1 = 0;
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &b[i]);
                c2[b[i]]++;
                if (a[i] == b[i]) a1++;
            }
            for (int i = 1; i <= 9; i++)
            {
                b1 += min(c1[i], c2[i]);
            }
            if (b[0] == 0) break;
            printf("    (%d,%d)\n", a1, b1 - a1);
        }
    }
}
