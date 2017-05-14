#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 10000 + 20;
struct qnode {
    int v;
    double c;
    qnode(int _v = 0, double _c = 0): v(_v), c(_c) {}
    bool operator <(const qnode &r)const {
        return c < r.c;
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
    for (int i = 1; i <= n; i++)dist[i] = 0;
    priority_queue<qnode>que;
    while (!que.empty())que.pop();
    dist[start] = 1;
    que.push(qnode(start, 1));
    qnode tmp;
    while (!que.empty()) {
        tmp = que.top();
        que.pop();
        int u = tmp.v;
        //cout << u << endl;
        if (vis[u])continue;
        vis[u] = true;
        for (int i = 0; i < E[u].size(); i++) {
            int v = E[tmp.v][i].v;
            double cost = E[u][i].cost;
            //cout << v << endl;
            //cout << cost << endl;
            if (!vis[v] && dist[v] < dist[u] * cost) {
                dist[v] = dist[u] * cost;
                //puts("111111");
                que.push(qnode(v, dist[v]));
            }
        }
    }
}
void addedge(int u, int v, double w) {
    E[u].push_back(Edge(v, w));
}
int n, m;
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) {
            E[i].clear();
        }
        while (m--) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            addedge(a, b, c / 100.0);
            addedge(b, a, c / 100.0);
        }
        Dijkstra(n, 1);
        printf("%.6f\n", dist[n] * 100 + 1e-8);
    }
}
