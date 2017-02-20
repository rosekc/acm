//2017-01-31-22.45
//

#include <bits/stdc++.h>
using namespace std;
int d1[55], d2[55];
int t1[55], t2[55];
int main()
{
    int n, l;
    scanf("%d%d", &n, &l);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &d1[i]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &d2[i]);
    }
    for (int i = 0; i < n - 1; i++)
    {
        t1[i] = d1[i + 1] - d1[i];
    }
    t1[n - 1] = l - d1[n - 1] + d1[0];
    for (int i = 0; i < n - 1; i++)
    {
        t2[i] = d2[i + 1] - d2[i];
    }
    t2[n - 1] = l - d2[n - 1] + d2[0];
    //printf("%d %d\n", t1[n - 1], t2[n - 1]);
    for (int i = 0; i < n; i++)
    {
        int f = 1;
        for (int j = 0; j < n; j++)
        {
            //printf("%d %d\n", t1[j] ,t2[(i + j) % n]);
            if (t1[j] != t2[(i + j) % n])
            {
                f = 0;
                //printf("%d %d\n", i, j);
                break;
            }
        }
        if (f)
        {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
}
