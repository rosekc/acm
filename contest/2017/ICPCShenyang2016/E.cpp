//2017-10-29-23.04
//E

#include <bits/stdc++.h>

using namespace std;

const int maxn = 100 + 10;
bool G[maxn][maxn];
int T, n, m, s;
vector<int> has;
vector<int> Gn[maxn];
int ans;
void dfs(int cur, int l) {
    if (l == s) {
        ans++;
        return;
    }
    for (int i : Gn[cur]) {
        bool ok = 1;
        for (int j : has) {
            if (!G[j][i]) {
                ok = 0;
                break;
            }
        }
        if (ok) {
            has.push_back(i);
            dfs(i, l + 1);
            has.pop_back();
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--) {
        int u, v;
        memset(G, 0, sizeof G);
        cin >> n >> m >> s;
        for (int i = 1; i <= n; i++) {
            Gn[i].clear();
        }
        while (m--) {
            cin >> u >> v;
            G[u][v] = G[v][u] = 1;
            Gn[u].push_back(v);
            //G[v].push_back(u);
        }
        ans = 0;
        for (int i = 1; i <= n; i++) {
            has.clear();
            has.push_back(i);
            dfs(i, 1);
        }
        cout << ans << endl;
    }
}
