#include <cstdio>
#include <cstring>

const int maxn = 10000 + 10;
int dge[maxn];

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        memset(dge, 0, sizeof(dge));
        for (int i = 1; i < n; i++)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            dge[a]++;
            dge[b]++;
        }
        int cnt = 1;
        for (int i = 1; i <= n; i++)
        {
            if (dge[i] == 1) cnt++;
        }
        printf("%d\n", cnt / 2);
    }
}
