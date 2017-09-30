// 2017-09-26 22:53:05
// Uva 1515

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;  //点数的最大值
const int MAXM = 400010;  //边数的最大值
const int INF = 0x3f3f3f3f;
struct Edge {
    int to, next, cap, flow;
} edge[MAXM];  //注意是MAXM
int tol;
int head[MAXN];
int gap[MAXN], dep[MAXN], pre[MAXN], cur[MAXN];
void init() {
    tol = 0;
    memset(head, -1, sizeof(head));
}
//加边，单向图三个参数，双向图四个参数
void addedge(int u, int v, int w, int rw = 0) {
    edge[tol].to = v;
    edge[tol].cap = w;
    edge[tol].next = head[u];
    edge[tol].flow = 0;
    head[u] = tol++;
    edge[tol].to = u;
    edge[tol].cap = rw;
    edge[tol].next = head[v];
    edge[tol].flow = 0;
    head[v] = tol++;
}
//输入参数：起点、终点、点的总数
//点的编号没有影响，只要输入点的总数
int sap(int start, int end, int N) {
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
char g[55][55];
int r, c;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int id(int i, int j) {
    return i * c + j;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T, d, f, b;
    cin >> T;
    while (T--) {
        cin >> c >> r >> d >> f >> b;
        int cost = 0;
        int s = r * c, t = s + 1;
        init();
        for (int i = 0; i < r; i++) {
            cin >> g[i];
            if (g[i][0] == '.') cost += f, g[i][0] = '#';
            if (g[i][c - 1] == '.') cost += f, g[i][c - 1] = '#';
        }
        for (int i = 0; i < c; i++) {
            if (g[0][i] == '.') cost += f, g[0][i] = '#';
            if (g[r - 1][i] == '.') cost += f, g[r - 1][i] = '#';
        }
        // cout << cost << endl;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (g[i][j] == '#') {
                    int cap = INF;
                    if (i != 0 && j != 0 && i != r - 1 && j != c - 1) {
                        cap = d;
                    }
                    addedge(s, id(i, j), cap);
                }else {
                    addedge(id(i, j), t, f);
                }
                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
                        addedge(id(i, j), id(nx, ny), b);
                    }
                }
            }
        }
        cout << cost + sap(s, t, t + 1) << endl;
    }
}