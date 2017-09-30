//2017-09-10-13.58
//1008

#include <bits/stdc++.h>

using namespace std;

const int maxn = 100000 + 100;
const int INF = (1 << 30);
struct Edge {
    int u, v, dist;
};
vector<Edge> edges;
vector<int> G[maxn];
int d[maxn], cnt[maxn];
bool inq[maxn];
int N;
void init(int n) {
    N = n;
    for (int i = 0; i < N; i++) G[i].clear();
    edges.clear();
}
void addedge(int u, int v, int dist) {
    edges.push_back({u, v, dist});
    int m = edges.size();
    G[u].push_back(m - 1);
}
bool solve(int s) {
    queue<int> q;
    memset(inq, 0, sizeof inq);
    memset(cnt, 0, sizeof cnt);
    for (int i = 0; i < N; i++) {
        d[i] = INF;
    }
    d[s] = 0;
    inq[s] = 1;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = 0;
        for (int i : G[u]) {
            Edge &e = edges[i];
            if (d[u] < INF && d[e.v] > d[u] + e.dist) {
                d[e.v] = d[u] + e.dist;
                if (!inq[e.v]) {
                    q.push(e.v);
                    inq[e.v] = 1;
                    if (++cnt[e.v] > N) {
                        return false;
                    }
                }
            }
        }
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        init(n + 2);
        int s = 0, t = n + 1;
        for (int i = 1; i <= n; i++) {
            int c;
            cin >> c;
            addedge(s, i, c);
            addedge(i, t, -c);
        }
        for (int i = 1; i < n; i++) {
            int u, v, c;
            cin >> u >> v >> c;
            addedge(u, v, c);
            addedge(v, u, c);
        }
        solve(s);
        cout << -d[t] << endl;
    }
}
