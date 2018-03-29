//2017-10-11-23.08
//LA 2957

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 6000;  //点数的最大值
const int MAXM = 100100;  //边数的最大值
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

const int maxm = 210;
int u[maxm], v[maxm];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k, s, t;
    while (cin >> n >> m >> k >> s >> t) {
        init();
        //k = 3;
        for (int i = 0; i < m; i++) {
            cin >> u[i] >> v[i];
        }
        int day = 1, flow = 0;
        for (;;) {
            for (int i = 1; i <= n; i++) {
                addedge((day - 1) * n + i, day * n + i, INF);
            }
            for (int i = 0; i < m; i++) {
                addedge((day - 1) * n + u[i], day * n + v[i], 1);
                addedge((day - 1) * n + v[i], day * n + u[i], 1);
            }
            flow += sap(s, t + day * n, t + day * n + 1, k - flow);
            //cout << flow << endl;
            if (k == flow) break;
            day++;
        }
        cout << day << endl;
        vector<int> pos(k, s);
        int idx = 0;
        for (int i = 1; i <= day; i++) {
            vector<int> f, t;
            idx += 2 * n;
            for (int j = 0; j < m; j++) {
                int f1 = edge[idx].flow;
                idx += 2;
                int f2 = edge[idx].flow;
                idx += 2;
                //cout << f1 << " " << f2 << " " << u[j] << endl;
                if (f1 == 1 && f2 == 0) {
                    f.push_back(u[j]);
                    t.push_back(v[j]);
                }
                if (f1 == 0 && f2 == 1) {
                    f.push_back(v[j]);
                    t.push_back(u[j]);
                }
            }
            //cout << idx << " " << tol << endl;
            cout << f.size();
            vector<bool> moved(k, 0);
            for (int j = 0; j < f.size(); j++) {
                for (int p = 0; p < k; p++) {
                    if (!moved[p] && f[j] == pos[p]) {
                        cout << ' ' << p + 1 << ' ' << t[j];
                        pos[p] = t[j];
                        moved[p] = 1;
                        break;
                    }
                }
            }
            cout << endl;
        }
    }
}
