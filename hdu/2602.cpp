//2016-11-19-19.38
//hdu 2602

#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int f[1010], w[1010], v[1010];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, c;
        scanf("%d%d", &n, &c);
        memset(f, 0, sizeof(f));
        for (int i = 0; i < n; i++) scanf("%d", &v[i]);
        for (int i = 0; i < n; i++) scanf("%d", &w[i]);
        for (int i = 0; i < n; i++)
        {
            for (int j = c; j >= 0; j--)
            {
                if (j >= w[i]) f[j] = max(f[j], f[j - w[i]] + v[i]);
            }
        }
        printf("%d\n", f[c]);
    }
}
