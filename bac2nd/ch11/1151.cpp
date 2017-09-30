//2017-09-06-16.28
//Uva 1151

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e3 + 100;
struct Edge {
    int u, v;
    long long w;
    bool operator <(const Edge &b)const & {
        return w < b.w;
    }
};
struct P {
    int x, y;
};
vector<int> sub[8];
int subc[8];
P p[maxn];
vector<Edge> e, es;
long long dist(long long x1, long long y1, long long x2, long long y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}
int fa[maxn];
int getfa(int x) {
    return x == fa[x] ? x : fa[x] = getfa(fa[x]);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    bool first = 1;
    while (T--) {
        es.clear();
        e.clear();
        int n, m;
        cin >> n >> m;
        iota(fa + 1, fa + 1 + n, 1);
        for (int i = 0; i < m; i++) {
            int t, a;
            cin >> t >> subc[i];
            sub[i].clear();
            while (t--) {
                cin >> a;
                sub[i].push_back(a);
            }
        }
        for (int i = 1; i <= n; i++) {
            cin >> p[i].x >> p[i].y;
            for (int j = 1; j <= i; j++) {
                e.push_back({i, j, dist(p[i].x, p[i].y, p[j].x, p[j].y)});
            }
        }
        sort(e.begin(), e.end());
        int cnt = 0;
        for (auto i : e) {
            int x = getfa(i.u);
            int y = getfa(i.v);
            if (x != y) {
                cnt++;
                fa[x] = y;
                es.push_back(i);
            }
            if (cnt == n - 1) {
                break;
            }
        }
        int ret = 0x3f3f3f3f;
        for (int i = (1 << (m + 1) - 1); i >= 0; i--) {
            int t = i, j = 0, ans = 0;
            cnt = 0;
            iota(fa + 1, fa + 1 + n, 1);
            while (t != 0) {
                if (t & 1) {
                    ans += subc[j];
                    for (int k : sub[j]) {
                        for (int p : sub[j]) {
                            int x = getfa(k);
                            int y = getfa(p);
                            if (x != y) {
                                fa[x] = y;
                                cnt++;
                            }
                        }
                    }
                }
                t >>= 1;
                j++;
            }
            for (auto ed : es) {
                int x = getfa(ed.u);
                int y = getfa(ed.v);
                if (x != y) {
                    //cout << ed.u << " " << ed.v << endl;
                    fa[x] = y;
                    ans += ed.w;
                }
                if (cnt == n - 1) {
                    break;
                }
            }
            //cout << ans << endl;
            ret = min(ret, ans);
        }
        if (!first) cout << endl;
        first = 0;
        cout << ret << endl;
    }
}
