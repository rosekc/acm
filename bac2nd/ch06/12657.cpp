//2016-09-13-20.41
//Uva 12657

#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100000 + 10;
int left[maxn], right[maxn];
void link(int L, int R)
{
    right[L] = R; left[R] = L;
}
int main()
{
    int con = 1, n, m;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        for (int i = 1; i <= n; i++)
        {
            left[i] = i - 1;
            right[i] = (i + 1) % (n + 1);
        }
        right[0] = 1;
        left[0] = n;
        int q, x, y;
        bool inv = 0;

        while (m--)
        {
            scanf("%d", &q);
            if (q == 4) inv = !inv;
            else
            {
                scanf("%d%d", &x, &y);
                if (q == 3 && right[y] == x) swap(x, y);
                if (q != 3 && inv) q = 3 - q;
                if (q == 1 && x == left[y]) continue;
                if (q == 2 && x == right[y]) continue;

                int lx = left[x], rx = right[x], ly = left[y], ry = right[y];
                if (q == 1)
                {
                    link(lx, rx); link(ly, x); link(x, y);
                }
                else if (q == 2)
                {
                    link(lx, rx); link(x, ry); link(y, x);
                }
                else if (q == 3)
                {
                    if (right[x] == y)
                    {
                        link(lx, rx); link(y, x); link(x, ry);
                    }
                    else
                    {
                        link(lx, y); link(y, rx); link(ly, x); link(x, ry);
                    }
                }
            }
        }
        int b = 0;
        long long ans = 0;
        for (int i = 1; i <= n; i++)
        {
            b = right[b];
            if (i % 2) ans += b;
        }
        if (inv && n % 2 == 0) ans = (long long)n * (n + 1) / 2 - ans;
        printf("Case %d: %lld\n", con++, ans);
    }
}
