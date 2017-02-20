//2017-02-16-13.59
//Uva 512

#include <bits/stdc++.h>

using namespace std;

const int maxn = 10000;
struct Command
{
    char c[5];
    int r1, c1, r2, c2;
    int a, x[20];
};
Command cmd[maxn];
int r, c, n;
bool simulate(int &tr, int &tc)
{
    for (int i = 0; i < n; i++)
    {
        Command &c = cmd[i];
        if (c.c[0] == 'E')
        {
            if (c.r1 == tr && c.c1 == tc) tr = c.r2, tc = c.c2;
            else if (c.r2 == tr && c.c2 == tc) tr = c.r1, tc = c.c1;
        }
        else
        {
            int dr = 0, dc = 0;
            for (int j = 0; j < c.a; j++)
            {
                int &x = c.x[j];
                if (c.c[0] == 'I')
                {
                    if (c.c[1] == 'R' && x <= tr) dr++;
                    else if (c.c[1] == 'C' && x <= tc) dc++;
                }
                else
                {
                    if (c.c[1] == 'R' && x == tr) return 0;
                    if (c.c[1] == 'C' && x == tc) return 0;
                    if (c.c[1] == 'R' && x < tr) dr--;
                    if (c.c[1] == 'C' && x < tc) dc--;
                }
            }
            tr += dr;
            tc += dc;
            //printf("dr=%ddc=%d\n", dr, dc);
        }
        //printf("%d %d\n", tr, tc);
    }
    return 1;
}
int main()
{
    int con = 1;
    while (scanf("%d%d", &r, &c) != EOF && r)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            Command &c = cmd[i];
            scanf("%s", c.c);
            if (c.c[0] == 'E')
            {
                scanf("%d%d%d%d", &c.r1, &c.c1, &c.r2, &c.c2);
            }
            else
            {
                scanf("%d", &c.a);
                for (int j = 0; j < c.a; j++)
                {
                    scanf("%d", &c.x[j]);
                }
            }
        }
        if (con > 1) puts("");
        printf("Spreadsheet #%d\n", con++);
        int rn, tr, tc;
        scanf("%d", &rn);
        while (rn--)
        {
            scanf("%d%d", &tr, &tc);
            printf("Cell data in (%d,%d) ", tr, tc);
            if (!simulate(tr, tc))
            {
                puts("GONE");
            }
            else
            {
                printf("moved to (%d,%d)\n", tr, tc);
            }
        }
    }
}
