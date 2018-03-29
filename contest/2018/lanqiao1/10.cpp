// 2018-03-29 17:04:59

#include <bits/stdc++.h>

using namespace std;

const int maxn = 100000 + 100;
int C[maxn];

inline int lowbit(int x) { return x & -x; }

int add(int x, int d) {
    while (x < maxn) {
        C[x] += d;
        x += lowbit(x);
    }
}

int sum(int x) {
    int ret = 0;
    while (x > 0) {
        ret += C[x];
        x -= lowbit(x);
    }
    return ret;
}

vector<int> g[maxn];
int ans[maxn];
bool vis[maxn];
vector<int> dfn;
int id[maxn];
int cnt[maxn];
int dfs(int x) {
    dfn.push_back(x);
    vis[x] = 1;
    for (int i = 0; i < g[x].size(); i++) {
        int nxt = g[x][i];
        if (!vis[nxt]) {
            cnt[x] += (dfs(nxt) + 1);
        }
    }
    //cout << x << ' ' << cnt[x] << endl;
    return cnt[x];
}

int main() {
    int n, p, u, v;
    cin >> n >> p;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(p);
    for (int i = 0; i < n; i++) {
        id[dfn[i]] = i + 1;
    }
    for (int i = 1; i <= n; i++) {
        //cout << i << endl;
        ans[i] = sum(id[i] + cnt[i]) - sum(id[i]);
        add(id[i], 1);
        //cout << i << ' ' << id[i] << ' ' << ans[i] << endl;
    }
    for (int i = 1; i <= n; i++) {
        if (i == 1) cout << ans[i];
        else cout << ' ' << ans[i];
    }
    cout << endl;
}