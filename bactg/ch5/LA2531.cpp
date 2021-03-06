// 2017-09-27 19:37:35
// LA2531

#include <bits/stdc++.h>
using namespace std;

const int maxn = 27;
int w[maxn], d[maxn], a[maxn][maxn];

const int MAXN = 1000;  //点数的最大值
const int MAXM = 20010;  //边数的最大值
const int INF = 0x3f3f3f3f;
struct Edge {
    int to, next, cap, flow;
} edge[MAXM];  //注意是MAXM
int tol;
int head[MAXN];
vector<int> G[MAXN];
int gap[MAXN], dep[MAXN], pre[MAXN], cur[MAXN];
void init(int n = MAXN) {
    tol = 0;
    memset(head, -1, sizeof(head));
    for (int i = 0; i < n; i++) G[i].clear();
}
//加边，单向图三个参数，双向图四个参数
void addedge(int u, int v, int w, int rw = 0) {
    edge[tol].to = v;
    edge[tol].cap = w;
    edge[tol].next = head[u];
    edge[tol].flow = 0;
    G[u].push_back(tol);
    head[u] = tol++;
    edge[tol].to = u;
    edge[tol].cap = rw;
    edge[tol].next = head[v];
    edge[tol].flow = 0;
    head[v] = tol++;
}
//输入参数：起点、终点、点的总数
//点的编号没有影响，只要输入点的总数
int sap(int start, int end, int N, int c = INF) {
    memset(gap, 0, sizeof(gap));
    memset(dep, 0, sizeof(dep));
    memcpy(cur, head, sizeof(head));
    int u = start;
    pre[u] = -1;
    gap[0] = N;
    int ans = 0;
    while (dep[start] < N) {
        if (u == end) {
            int Min = INF;
            for (int i = pre[u]; i != -1; i = pre[edge[i ^ 1].to])
                if (Min > edge[i].cap - edge[i].flow)
                    Min = edge[i].cap - edge[i].flow;
            if (ans + Min > c) {
                Min = c - ans;
            }
            for (int i = pre[u]; i != -1; i = pre[edge[i ^ 1].to]) {
                edge[i].flow += Min;
                edge[i ^ 1].flow -= Min;
            }
            u = start;
            ans += Min;
            if (ans == c) return ans;
            continue;
        }
        bool flag = false;
        int v;
        for (int i = cur[u]; i != -1; i = edge[i].next) {
            v = edge[i].to;
            if (edge[i].cap - edge[i].flow && dep[v] + 1 == dep[u]) {
                flag = true;
                cur[u] = pre[v] = i;
                break;
            }
        }
        if (flag) {
            u = v;
            continue;
        }
        int Min = N;
        for (int i = head[u]; i != -1; i = edge[i].next)
            if (edge[i].cap - edge[i].flow && dep[edge[i].to] < Min) {
                Min = dep[edge[i].to];
                cur[u] = i;
            }
        gap[dep[u]]--;
        if (!gap[dep[u]]) return ans;
        dep[u] = Min + 1;
        gap[dep[u]]++;
        if (u != start) u = edge[pre[u] ^ 1].to;
    }
    return ans;
}
int n;
int id(int u, int v) {
    return (u - 1) * n + v;
}
int id(int u) {
    return n * n + u;
}

bool ok(int i) {
    int sum = w[i];
    int t = n * (n + 1) + 1;
    int maxflow = 0;
    init(t + 1);
    for (int j = 1; j <= n; j++) sum += a[i][j];
    for (int j = 1; j <= n; j++) {
        if (sum < w[j]) return 0;
    }
    for (int u = 1; u <= n; u++) {
        for (int v = u + 1; v <= n; v++) {
            addedge(0, id(u, v), a[u][v]);
            addedge(id(u, v), id(u), INF);
            addedge(id(u, v), id(v), INF);
            maxflow += a[u][v];
        }
        if (sum > w[u]) addedge(id(u), t, sum - w[u]);
    }
    //cout << maxflow << endl;
    return (maxflow == sap(0, t, t + 1));
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> w[i] >> d[i];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> a[i][j];
            }
        }
        bool first = 1;
        for (int i = 1; i <= n; i++) {
            if (ok(i)) {
                if (!first) cout << ' ';
                cout << i;
                first = 0;
            }
        }
        cout << endl;
    }
}
