//2017-09-09-13.31
//H

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;
struct E{
    int v, l;
};
vector<E> G[maxn];
int n, m;
int d[maxn];
int dfs(int c) {
    if (d[c] != -1) return d[c];
    int ans = 0;
    for (E i : G[c]) {
        ans = max(dfs(i.v) + i.l, ans);
    }
    return d[c] = ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            G[i].clear();
            d[i] = -1;
        }
        while (m--) {
            int x, y, l;
            cin >> x >> y >> l;
            G[x].push_back({y, l});
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans = max(ans, dfs(i));
        }
        cout << ans << endl;
    }
}
