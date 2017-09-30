//2017-08-22-12.07
//F

#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e4 + 10;

const int MAXN = maxn;//点数
const int MAXM = 10 * maxn;//边数
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
int indeg[maxn], outdeg[maxn];
void built(int n) {
    memset(G, 0, sizeof G);
    for (int u = 1; u <= n; u++)
        for (int i = head[u]; i != -1; i = edge[i].next) {
            int v = edge[i].to;
            //cout << u << ' ' << v << endl;
            //cout << Belong[u] << ' ' << Belong[v] << endl << endl;;
            if (Belong[u] != Belong[v]) {
                G[Belong[u]][Belong[v]] = 1;
            }
        }
}

int cal(int n) {
    memset(indeg, 0, sizeof indeg);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (G[i][j]) {
                indeg[j]++;
                outdeg[i]++;
            }
        }
    }
    int zin = 0, zout = 0;
    for (int i = 1; i <= n; i++) {
        if (!indeg[i]) zin++;
        if (!outdeg[i]) zout++;
    }
    return max(zin, zout);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int m, n, u, v;
        cin >> n >> m;
        init();
        for (int i = 0; i < m; i++)  {
            cin >> u >> v;
            addedge(u, v);
        }
        solve(n);
        built(n);
        //        cout << scc << endl;
        //        for (int i= 1; i <= scc; i++) {
        //            for (int j = 1; j <= scc; j++) {
        //                cout << G[i][j] << ' ';
        //            }
        //            cout << endl;
        //        }
        cout << cal(n) << endl;
    }
}

