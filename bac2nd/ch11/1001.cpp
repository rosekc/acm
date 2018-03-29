//2017-10-19-23.28
//Uva1001

#include <bits/stdc++.h>

using namespace std;

const double INF = 1e15;
const int MAXN = 120;
struct qnode {
    int v;
    double c;
    qnode(int _v = 0, double _c = 0): v(_v), c(_c) {}
    bool operator <(const qnode &r)const {
        return c > r.c;
    }
};
struct Edge {
    int v;
    double cost;
    Edge(int _v = 0, double _cost = 0): v(_v), cost(_cost) {}
};
vector<Edge>E[MAXN];
bool vis[MAXN];
double dist[MAXN];
void Dijkstra(int n, int start) { //点的编号从1开始
    memset(vis, false, sizeof(vis));
    for (int i = 0; i < n; i++)dist[i] = INF;
    priority_queue<qnode>que;
    while (!que.empty())que.pop();
    dist[start] = 0;
    que.push(qnode(start, 0));
    qnode tmp;
    while (!que.empty()) {
        tmp = que.top();
        que.pop();
        int u = tmp.v;
        if (vis[u])continue;
        vis[u] = true;
        for (int i = 0; i < E[u].size(); i++) {
            int v = E[tmp.v][i].v;
            double cost = E[u][i].cost;
            if (!vis[v] && dist[v] > dist[u] + cost) {
                dist[v] = dist[u] + cost;
                que.push(qnode(v, dist[v]));
            }
        }
    }
}
void addedge(int u, int v, double w) {
    E[u].push_back(Edge(v, w));
}

int x[MAXN], y[MAXN], z[MAXN], r[MAXN];

double dis(int x1, int y1, int z1, int x2, int y2, int z2) {
    double re = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2);
    return sqrt(re);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, sx, sy, sz, ex, ey, ez;
    int kase = 1;
    while (cin >> n && n != -1) {
        int s = 0, e = n + 1;
        for (int i = 0; i <= e; i++) E[i].clear();
        for (int i = 1; i <= n; i++) {
            cin >> x[i] >> y[i] >> z[i] >> r[i];
        }
        cin >> sx >> sy >> sz >> ex >> ey >> ez;
        addedge(s, e, dis(sx, sy, sz, ex, ey, ez));
        for (int i = 1; i <= n; i++) {
            addedge(s, i, max(.0, dis(sx, sy, sz, x[i], y[i], z[i]) - r[i]));
            addedge(i, e, max(.0, dis(ex, ey, ez, x[i], y[i], z[i]) - r[i]));
            for (int j = 1; j <= n; j++) {
                if (i != j) {
                    addedge(i, j, max(.0, dis(x[i], y[i], z[i], x[j], y[j], z[j]) - r[i] - r[j]));
                }
            }
        }
        Dijkstra(e + 1, s);
        cout << "Cheese " << kase++ << ": Travel time = " << setprecision(0) << fixed << dist[e] * 10 << " sec" << endl;
    }
}
