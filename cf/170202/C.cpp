//2017-02-02-22.30
//C

#include <bits/stdc++.h>
using namespace std;

vector<int> d[100000 + 100];
int c[100000 + 100];
int rt, n;
map<pair<int, int>, bool> m;
bool bfs(int i, int fa)
{
    if (m.find({i, fa}) != m.end()) return m[{i, fa}];
    vector<int>::iterator it;
    //printf(" %d %d\n", i, fa);
    for (it = d[i].begin(); it != d[i].end(); it++)
    {
        if (*it == fa) continue;
        if ((fa == -1 || c[i] == c[*it]) && bfs(*it, i)) {continue;}
        else {m.insert({{i, fa}, 0}); return 0;}
    }
    m.insert({{i, fa}, 1});
    return 1;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        d[u].push_back(v);
        d[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &c[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        if (bfs(i, -1))
        {
            printf("YES\n%d\n", i);
            return 0;
        }
    }
    puts("NO");
}
