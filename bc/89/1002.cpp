//2016-10-29-19.14
//Bestcoder 89 1002

#include <bits/stdc++.h>
using namespace std;
int d[1000000 + 100];
int x, k, t;
deque<pair<int, int> > q;
int getd(int i)
{
    if (d[i] != -1) return d[i];
    if (i == 1) return d[i] = 0;
    while (!q.empty() && q.front().first < i - t) q.pop_front();
    while (!q.empty() && q.back().second >= d[i - 1]) q.pop_back();
    q.push_back({i - 1, d[i - 1]});
    int minj = q.front().second;
    if (i % k == 0 && k != 1)
    {
        return d[i] = min(minj, d[i / k]) + 1;
    }
    else
    {
        return d[i] = minj + 1;
    }
}
int main()
{
    int c;
    scanf("%d", &c);
    while (c--)
    {
        scanf("%d%d%d", &x, &k, &t);
        memset(d, -1, sizeof d);
        while (!q.empty()) q.clear();
        for (int i = 1; i <= x; i++)
        {
            getd(i);
        }
        printf("%d\n", d[x]);
    }
}
