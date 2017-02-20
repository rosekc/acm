//2017-01-31-23.26
//

#include <bits/stdc++.h>
using namespace std;

bool issign(char in)
{
    return in == '#' || in == '*' || in == '&';
}

char d[55][55];
int mn[55][3];
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", d[i]);
    }
    memset(mn, 0x0f, sizeof mn);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            //puts("1");
            if (isdigit(d[i][j])) mn[i][0] = min(min(j, m - j), mn[i][0]);
            if (islower(d[i][j])) mn[i][1] = min(min(j, m - j), mn[i][1]);
            if (issign(d[i][j])) mn[i][2] = min(min(j, m - j), mn[i][2]);
        }
    }
    int re = 0x3f3f3f3f;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            for (int k = j + 1; k < n; k++)
            {
                int a = mn[i][0] + mn[j][1] + mn[k][2];
                a = min(a, mn[i][0] + mn[j][2] + mn[k][1]);
                a = min(a, mn[i][1] + mn[j][0] + mn[k][2]);
                a = min(a, mn[i][1] + mn[j][2] + mn[k][0]);
                a = min(a, mn[i][2] + mn[j][0] + mn[k][1]);
                a = min(a, mn[i][2] + mn[j][1] + mn[k][0]);
                re = min(re, a);
                //printf("  %d\n", re);
            }

    printf("%d\n", re);
}
