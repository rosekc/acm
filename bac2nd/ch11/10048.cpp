//2017-08-23-23.06
//Uva 10048

#include <bits/stdc++.h>
using namespace std;

const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
int G[maxn][maxn];

int main() {
    int c, s, q;
    int kase = 1;
    while (cin >> c >> s >> q && c) {
        if (kase != 1) puts("");
        memset(G, 0x3f, sizeof G);
        for (int i = 1; i <= c; i++) {
            G[i][i] = 0;
        }
        for(int i = 0; i < s; i++) {
            int u, v, cost;
            cin >> u >> v >> cost;
            if (cost < G[u][v]) {
                G[u][v] = G[v][u] = cost;
            }
        }
        for (int k = 1; k <= c; k++) {
            for (int i = 1; i <= c; i++) {
                for (int j = 1; j <= c; j++) {
                    G[i][j] = min(G[i][j], max(G[i][k], G[k][j]));
                }
            }
        }
        printf("Case #%d\n", kase++);
        while (q--) {
            int u, v;
            cin >> u >> v;
            if (G[u][v] < inf) {
                cout << G[u][v] << endl;
            }else puts("no path");
        }
    }
}
