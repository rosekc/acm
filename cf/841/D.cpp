//2017-08-19-00.28
//D

#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 10;

vector<pair<int, int> > G[maxn];
int a[maxn];

vector<int> ans;

bool dfs(int u) {
    for (auto v : G[u]) {
        if (a[v.first] == -1) {
            ans.push_back(v.second);
            return 1;
        }
    }
}

int main() {
    int n, m, u, v;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        G[u].push_back({v, i});
        G[v].push_back({u, i});
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] == 1) dfs(i);
    }
}
