#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

struct bid
{
    int t;
    int p;
    char name[10];
};
bool cmp(const bid &a, const bid &b)
{
    if (a.t == b.t)
    {
        return a.p < b.p;
    }
    return a.t < b.t;
}
bid d[100 + 10];

int main()
{
    int u, m;
    while (scanf("%d%d", &u, &m) != EOF)
    {
        int con = 0;
        for (int i = 0; i < m; i++)
        {
            int t;
            char tc[10];
            scanf("%s%d", tc, &t);
            bool flag = 0;
            for (int i = 0; i < con; i++)
            {
                if (d[i].p == t)
                {
                    d[i].t++;
                    flag = 1;
                    break;
                }
            }
            if (!flag)
            {
                d[con].t = 1;
                d[con].p = t;
                strcpy(d[con++].name, tc);
            }
        }
        sort(d, d + con, cmp);
        printf("The winner is %s\n", d[0].name);
        printf("The price is %d\n", d[0].p);
    }
}
