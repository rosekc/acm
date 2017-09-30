//2017-09-16-23.55
//Uva 658

#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int c;
    string u, v;
};
Edge e[150];
struct State {
    int cur, cost;
    bool operator<(const State& b)const & {
        return cost > b.cost;
    }
};
int d[(1 << 21)];
bool done[(1 << 21)];

const int INF = 1000000000;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, kase = 1;
    while (cin >> n >> m && n) {
        for (int i = 0; i < m; i++) {
            cin >> e[i].c >> e[i].u >> e[i].v;
        }
        int cur = (1 << n) - 1;
        for (int i = 0; i <= cur; i++) {
            d[i] = INF;
            done[i] = 0;
        }
        priority_queue<State> q;
        q.push({cur, 0});
        d[cur] = 0;
        while (!q.empty()) {
            auto x = q.top();
            q.pop();
            int u = x.cur;
            if (u == 0) break;
            if (done[u]) continue;
            done[u] = 1;
            for (int i = 0; i < m; i++) {
                bool ok = 1;
                for (int j = 0; j < n; j++) {
                    if (e[i].u[j] == '-' && (u & (1 << j))) {
                        ok = false;
                        break;
                    }
                    if (e[i].u[j] == '+' && !(u & (1 << j))) {
                        ok = false;
                        break;
                    }
                }
                if (!ok) continue;
                int v = u;
                for (int j = 0; j < n; j++) {
                    if (e[i].v[j] == '+') {
                        v |= (1 << j);
                    }
                    if (e[i].v[j] == '-') {
                        v &= ~(1 << j);
                    }
                }
                if (d[v] > d[u] + e[i].c) {
                    d[v] = d[u] + e[i].c;
                    q.push({v, d[v]});
                }
            }
        }
        //if (kase != 1) cout << '\n';
        cout <<  "Product " << kase++ << "\n";
        if (d[0] < INF) {
            cout << "Fastest sequence takes " << d[0] << " seconds.\n\n";
        } else {
            cout << "Bugs cannot be fixed.\n\n";
        }
    }
}
