//2017-02-24-00.06
//C

#include <bits/stdc++.h>

using namespace std;

const int maxn = 10e5 + 10;
long long sum[maxn];
map<long long, long long> m;
vector<long long> kn;
int main()
{
    int n, k, t;
    scanf("%d%d", &n, &k);
    long long tt = 1;
    while (1)
    {
        kn.push_back(tt);
        if (k == 1 || (k == -1 && tt == -1) || tt > (10e14 / abs(k)) || tt < (-10e14 / abs(k))) break;
        tt *= k;
    }
    long long re = 0;
    for (auto j : kn) m[j]++;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &t);
        sum[i] = sum[i - 1] + t;
        re += m[sum[i]];
        for (auto j : kn) m[sum[i] + j]++;
    }
    printf("%lld\n", re);
}
