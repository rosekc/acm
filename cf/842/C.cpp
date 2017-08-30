//2017-08-30-00.18
//C

#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 100;
vector<int> G[maxn];
int a[maxn];
int ans[maxn];
int dfs(int u, int fa, int gcd) {
    int ngcd = __gcd(gcd, a[u]);
    if (u != 1) ans[u] = max(gcd, max(ngcd, __gcd(ans[fa], a[u])));
    for (int v : G[u]) {
        if (v != fa) {
            dfs(v, u, ngcd);
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n ;i++) {
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    ans[1] = a[1];
    dfs(1, -1, a[1]);
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
}
