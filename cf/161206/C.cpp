//2016-12-06-23.32
//C

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int d[150];
int v[150];
int gcd(int a, int b)
{
    if (a < b)
        swap(a, b);
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        int re = 1;
        bool f = 0;
        memset(v, 0, sizeof v);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &d[i]);
        }
        for (int i = 1; i <= n; i++)
        {
            int con = 0;
            if (v[i] != 0) continue;
            int t = d[i];
            v[i] = i;
            while (1)
            {
                if (t == i)
                {
                    con++;
                    if (con % 2 == 0) con /= 2;
                    re = (re * con) / gcd(re, con);
                    break;
                }
                if (v[t] != 0) {f = 1; break;}
                v[t] = i;
                if (t == d[t]) {f = 1; break;}
                t = d[t];
                con++;
            }
            if (f) break;
        }
        if (f) puts("-1");
        else printf("%d\n", re);
    }
}
