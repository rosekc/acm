//2017-03-09-23.19
//HDU 1257

#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e5 + 100;
int f[maxn], d[maxn], n;

int main()
{
    while (scanf("%d", &n) != EOF)
    {
        int re = 0;
        f[0] = 30000;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &d[i]);
            int ok = 0;
            for (int j = 0; j <= re; j++)
            {
                if (f[j] >= d[i])
                {
                    f[j] = d[i];
                    ok = 1;
                    break;
                }
            }
            if (!ok)
            {
                f[++re] = d[i];
            }
        }
        printf("%d\n", re + 1);
    }
}
