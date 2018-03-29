// 2017-09-27 19:40:03
// Uva11248

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;  //点数的最大值
const int MAXM = 400010;  //边数的最大值
const int INF = 0x3f3f3f3f;
struct Edge {
    int to, next, cap, flow;
} edge[MAXM];  //注意是MAXM
int tol;
int head[MAXN];
vector<int> G[MAXN];
int gap[MAXN], dep[MAXN], pre[MAXN], cur[MAXN];
void init(int n) {
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
int sap(int start, int end, int N, int c) {
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
            for (int i = pre[u]; i != -1; i = pre[edge[i ^ 1].to]) {
                edge[i].flow += Min;
                edge[i ^ 1].flow -= Min;
            }
            u = start;
            ans += Min;
            if (ans > c) return ans;
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
bool vis[MAXN];
void bfs(int t) {
    memset(vis, 0, sizeof vis);
    queue<int> q;
    q.push(t);
    vis[t] = 1;
    while (!q.empty()) {
        int c = q.front();
        q.pop();
        for (int p = head[c]; p != -1; p = edge[p].next) {
            Edge &e = edge[p ^ 1];
            int from = edge[p].to;
            if (!vis[from] && e.cap > e.flow) {
                vis[from] = 1;
                q.push(from);
            }
        }
    }
}
vector<int> min_cut(int t) {
    bfs(t);
    vector<int> res;
    for (int i = 0; i < tol; i++) {
        Edge &e = edge[i];
        int from = edge[i^1].to;
        if (!vis[from] && vis[e.to] && e.cap > 0) {
            res.push_back(i);
        }
    }
    return res;
}
void cls() {
    for (int i = 0; i < tol; i++) {
        edge[i].flow = 0;
    }
}
bool cmp(int a, int b) {
    if (edge[a^1].to == edge[b^1].to) {
        return edge[a].to < edge[b].to;
    }
    return edge[a^1].to < edge[b^1].to;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, e, c, u, v, cap;
    int kase = 1;
    while (cin >> n >> e >> c && n) {
        init(n + 1);
        for (int i = 0; i < e; i++) {
            cin >> u >> v >> cap;
            addedge(u, v, cap);
        }
        int f = sap(1, n, n + 1, c);
        cout << "Case " << kase++ << ": ";
        if (f >= c) {
            cout << "possible" << endl;
            continue;
        }
        auto cut = min_cut(n);
        for (int i = 0; i < tol; i++) {
            edge[i].cap -= edge[i].flow;
        }
        vector<int> ans;
        for (int i : cut) {
            cls();
            edge[i].cap = c;
            if (sap(1, n, n + 1, c) + f >= c) {
                ans.push_back(i);
            }
            edge[i].cap = 0;
        }
        if (ans.empty()) {
            cout << "not possible" << endl;
        }else {
            sort(ans.begin(), ans.end(), cmp);
            cout << "possible option:("
                << edge[ans[0]^1].to << ',' << edge[ans[0]].to << ')';
            for (int i = 1; i < ans.size(); i++) {
                cout << ",(" << edge[ans[i]^1].to << ',' << edge[ans[i]].to << ')';
            }
            cout << endl;
        }
    }
}
