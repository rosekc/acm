//2017-08-13-00.01
//C

#include <bits/stdc++.h>

using namespace std;
const int MAXN = 100000 + 10;
struct Edge {
    int v;
    Edge(int _v = 0): v(_v) {}
};

vector<Edge> E[MAXN];
bool vis[MAXN];
void addedge(int u, int v) {
    for (auto i : E[u]) {
        if (i.v == v) continue;
    }
    E[u].push_back(Edge(v));
}
double dfs(int cur, int p, int pre) {
    double ans = 0;
    int c = 0;
    for (auto i : E[cur]) {
        if (i.v != pre) {
            ans += dfs(i.v, p + 1, cur);
            c++;
        }
    }
    //cout << cur << " " << ans << endl;
    if (c == 0) {
        return p;
    }
    return ans / c;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, u, v;
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        addedge(u, v);
        addedge(v, u);
    }
    cout << dfs(1, 0, 1) << endl;
}
