//2017-08-13-15.21
//1005

#include <bits/stdc++.h>

using namespace std;
const int N = 6000;
const int MAXN = 6000;
const int MAXM = 60000;
const int INF = (1 << 30) - 1;
struct Edge {
    int from, to, cap, flow, cost;
    Edge(int u, int v, int ca, int f, int co): from(u), to(v), cap(ca), flow(f), cost(co) {};
};

struct MCMF {
    int n, m, s, t;
    vector<Edge> edges;
    vector<int> G[N];
    int inq[N];//是否在队列中
    int d[N];//距离
    int p[N];//上一条弧
    int a[N];//可改进量

    void init(int n) { //初始化
        this->n = n;
        for (int i = 0; i < n; i++)
            G[i].clear();
        edges.clear();
    }

    void addedge(int from, int to, int cap, int cost) { //加边
        edges.push_back(Edge(from, to, cap, 0, cost));
        edges.push_back(Edge(to, from, 0, 0, -cost));
        int m = edges.size();
        G[from].push_back(m - 2);
        G[to].push_back(m - 1);
    }

    bool SPFA(int s, int t, int &flow, int &cost) { //寻找最小费用的增广路，使用引用同时修改原flow,cost
        for (int i = 0; i < n; i++)
            d[i] = INF;
        memset(inq, 0, sizeof(inq));
        d[s] = 0;
        inq[s] = 1;
        p[s] = 0;
        a[s] = INF;
        queue<int> Q;
        Q.push(s);
        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();
            inq[u]--;
            for (int i = 0; i < G[u].size(); i++) {
                Edge& e = edges[G[u][i]];
                if (e.cap > e.flow && d[e.to] > d[u] + e.cost) { //满足可增广且可变短
                    d[e.to] = d[u] + e.cost;
                    p[e.to] = G[u][i];
                    a[e.to] = min(a[u], e.cap - e.flow);
                    if (!inq[e.to]) {
                        inq[e.to]++;
                        Q.push(e.to);
                    }
                }
            }
        }
        if (d[t] == INF) return false; //汇点不可达则退出
        flow += a[t];
        cost += d[t] * a[t];
        int u = t;
        while (u != s) { //更新正向边和反向边
            edges[p[u]].flow += a[t];
            edges[p[u] ^ 1].flow -= a[t];
            u = edges[p[u]].from;
        }
        return true;
    }

    int MincotMaxflow(int s, int t) {
        int flow = 0, cost = 0;
        while (SPFA(s, t, flow, cost));
        return cost;
    }
};
int main() {
    int n, m, a, b, c, d;
    int s = 0, t;
    MCMF mc;
    while (cin >> n >> m) {
        t = n + 1;
        mc.init(t + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a >> b >> c >> d;
            mc.addedge(s, i, b, a);
            mc.addedge(i, t, d, -c);
        }
        for (int i = 1; i <= m; i++) {
            int x, y, k;
            cin >> x >> y >> k;
            mc.addedge(x, y, INF, k);
            mc.addedge(y, x, INF, k);
        }
        cout << -mc.MincotMaxflow(s, t) << endl;
    }
    return 0;
}
