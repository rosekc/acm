//2017-10-28-23.36
//B

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e3 + 100;

const int MAXN = maxn;//点数
const int MAXM = maxn * maxn;//边数
struct Edge {
    int to, next;
} edge[MAXM];
int head[MAXN], tot;
int Low[MAXN], DFN[MAXN], Stack[MAXN], Belong[MAXN]; //Belong数组的值是1~scc
int Index, top;
int scc;//强连通分量的个数
bool Instack[MAXN];
int num[MAXN];//各个强连通分量包含点的个数，数组编号1~scc
//num数组不一定需要，结合实际情况
void addedge(int u, int v) {
    edge[tot].to = v;
    edge[tot].next = head[u];
    head[u] = tot++;
}
bool G[maxn][maxn];
void Tarjan(int u) {
    int v;
    Low[u] = DFN[u] = ++Index;
    Stack[top++] = u;
    Instack[u] = true;
    for (int i = head[u]; i != -1; i = edge[i].next) {
        v = edge[i].to;
        if ( !DFN[v] ) {
            Tarjan(v);
            if ( Low[u] > Low[v] )Low[u] = Low[v];
        } else if (Instack[v] && Low[u] > DFN[v])
            Low[u] = DFN[v];
    }
    if (Low[u] == DFN[u]) {
        scc++;
        do {
            v = Stack[--top];
            Instack[v] = false;
            Belong[v] = scc;
            num[scc]++;
        } while ( v != u);
    }
}
void solve(int N) {
    memset(DFN, 0, sizeof(DFN));
    memset(Instack, false, sizeof(Instack));
    memset(num, 0, sizeof(num));
    Index = scc = top = 0;
    for (int i = 1; i <= N; i++)
        if (!DFN[i])
            Tarjan(i);
}
void init() {
    tot = 0;
    memset(head, -1, sizeof(head));
}
int indeg[maxn];
int min_cost[maxn];
void built(int n) {
    memset(G, 0, sizeof G);
    memset(indeg, 0, sizeof indeg);
    for (int u = 1; u <= n; u++)
        for (int i = head[u]; i != -1; i = edge[i].next) {
            int v = edge[i].to;
            //cout << u << ' ' << v << endl;
            //cout << Belong[u] << ' ' << Belong[v] << endl << endl;;
            if (Belong[u] != Belong[v]) {
                G[Belong[u]][Belong[v]] = 1;
                //indeg[Belong[v]]++;
            }
        }
}

bool topu(int n) {
    memset(indeg, 0, sizeof indeg);
    for(int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (G[i][j]) indeg[j]++;
        }
    }
//    queue<int> q;
//    for (int i = 1; i <= scc; i++) {
//        if (indeg[i] == 0) {
//            q.push(i);
//        }
//    }
//    //cout << scc << endl;
//    //cout << q.size() << endl;
//    while (!q.empty()) {
//        if (q.size() >= 2) return 0;
//        int c = q.front();
//        q.pop();
//        for (int i = 1; i <= scc; i++) {
//            if (G[c][i] && --indeg[i] == 0) {
//                q.push(i);
//            }
//        }
//    }
//    return 1;
}
long long x[maxn], y[maxn], r[maxn];
int c[maxn];

long long dist(int a, int b) {
    return (x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, n, kase = 0;
    cin >> T;
    while (T--) {
        cin >> n;
        init();
        for (int i = 1; i <= n; i++) {
            cin >> x[i] >> y[i] >> r[i] >> c[i];
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i != j && dist(i, j) <= 1ll * r[i] * r[i]) {
                    addedge(i, j);
                    //cout << i << " " << j << endl;
                }
            }
        }
        solve(n);
        built(n);
        topu(scc);
        //cout << scc << endl;
        int ans = 0;
        memset(min_cost, 0x3f, sizeof min_cost);
        for (int i = 1; i <= n ; i++) {
            min_cost[Belong[i]] = min(min_cost[Belong[i]], c[i]);
        }
        for (int i = 1; i <= scc; i++) {
            if (indeg[i] == 0) ans += min_cost[i];
        }
        cout << "Case #" << ++kase << ": " << ans << endl;
    }
}
