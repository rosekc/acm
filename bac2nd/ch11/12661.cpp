//2017-09-22-22.46
//Uva 12661

#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 1000010;
struct qnode {
    int v;
    int c;
    qnode(int _v = 0, int _c = 0): v(_v), c(_c) {}
    bool operator <(const qnode &r)const {
        return c > r.c;
    }
};
struct Edge {
    int v, a, b, cost;
};
vector<Edge>E[MAXN];
bool vis[MAXN];
int dist[MAXN];
void Dijkstra(int n, int start) { //点的编号从1开始
    memset(vis, false, sizeof(vis));
    for (int i = 1; i <= n; i++)dist[i] = INF;
    priority_queue<qnode>que;
    while (!que.empty())que.pop();
    dist[start] = 0;
    que.push(qnode(start, 0));
    qnode tmp;
    while (!que.empty()) {
        tmp = que.top();
        que.pop();
        int u = tmp.v;
        //cout << u << " " << tmp.c << endl;
        if (vis[u])continue;
        vis[u] = true;
        for (int i = 0; i < E[u].size(); i++) {
            auto &ne = E[u][i];
            int v = ne.v;
            int cost = ne.cost;
            int a = ne.a, b = ne.b;
            int t = tmp.c % (a + b);
            if (!vis[v]) {
                if (t + cost <= a && tmp.c + cost < dist[v]) {
                    que.push({v, tmp.c + cost});
                    dist[v] = tmp.c + cost;
                }
                int cc = tmp.c + (a + b - (tmp.c % (a + b))) + cost;
                if (cost <= a && cc < dist[v]) {
                    que.push({v, cc});
                    dist[v] = cc;
                }
            }
        }
    }
}
void addedge(int u, int v, int w, int a, int b) {
    E[u].push_back({v, w, a, b});
}
void init(int n) {
    for (int i = 1; i <= n; i++) {
        E[i].clear();
    }
}
int main() {
    int n, m, u, v, a, b, c, s, t, kase = 1;
    while (cin >> n >> m >> s >> t) {
        init(n);
        for (int i = 0; i < m; i++) {
            cin >> u >> v >> a >> b >> c;
            addedge(u, v, a, b, c);
        }
        Dijkstra(n, s);
        cout << "Case " << kase++ << ": " << dist[t] << endl;
    }
}
