//2017-09-06-15.08
//Uva 1395

#include <bits/stdc++.h>

using namespace std;

const int maxn = 100 + 20;
struct Edge {
    int u, v, w;
    bool operator <(const Edge& b) {
        return w < b.w;
    }
};
vector<Edge> Es;

int fa[maxn];
int getfa(int x) {
    return x == fa[x] ? x : fa[x] = getfa(fa[x]);
}
int main() {
    int n, m;
    while (cin >> n >> m && n) {
        iota(fa + 1, fa + n + 1, 1);
        Es.clear();
        for (int i = 1; i <= m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            Es.push_back({u, v, w});
        }
        sort(Es.begin(), Es.end());
        int t, cnt, ans = 0x3f3f3f3f;
        for (int l = 0; l < m; l++) {
            cnt = 0;
            for (int r = l; r < m; r++) {
                int x = getfa(Es[r].u);
                int y = getfa(Es[r].v);
                if (x != y) {
                    fa[x] = y;
                    t += Es[r].w;
                    cnt++;
                }
                if (cnt == n - 1) {
                    iota(fa + 1, fa + n + 1, 1);
                    ans = min(ans, Es[r].w - Es[l].w);
                    //cout << l << " " << r << endl;
                    break;
                }
            }
        }
        if (ans != 0x3f3f3f3f) cout << ans << endl;
        else cout << -1 << endl;
    }
}
