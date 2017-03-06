//2017-02-25-19.29
//1002

#include <bits/stdc++.h>

using namespace std;

const int maxn = 100000 + 100;

vector<int> bd[maxn];
int gd[maxn];
int main()
{
    int t, n, m, k, a, b;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d%d", &n, &m, &k);
        for (int i = 1; i <= n; i++)
        {
            bd[i].clear();
        }
        memset(gd, 0, sizeof gd);
        while (k--)
        {
            scanf("%d%d", &a, &b);
            bd[a].push_back(b);
            gd[b]++;
        }
        long long ans = 0;
        for (int i = 1; i <= n; i++)
        {
            long long tmp = (bd[i].size() - 1);
            for (auto j : bd[i])
            {
                ans += (gd[j] - 1) * tmp;
            }
        }
        printf("%lld\n", ans * 2);
    }
}
