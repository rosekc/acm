//2017-10-22-00.08
//Uva 821

#include <bits/stdc++.h>

using namespace std;

const int maxn = 120;
const int INF = 100000;
int d[maxn][maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int u, v, kase = 1;
    while (cin >> u >> v && u) {
        for (int i = 1; i < maxn; i++) {
            for (int j = 1; j < maxn; j++) {
                d[i][j] = INF;
            }
            d[i][i] = 0;
        }
        d[u][v] = 1;
        while (cin >> u >> v && u) {
            d[u][v] = 1;
        }
        for (int k = 1; k < maxn; k++) {
            for (int i = 1; i < maxn; i++) {
                for (int j = 1; j < maxn; j++) {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
        int p = 0;
        int cnt = 0;
        for (int i = 1; i < maxn; i++) {
            for (int j = 1; j < maxn; j++) {
                if (i != j && d[i][j] < INF) {cnt++; p += d[i][j];}
            }
        }
        cout << p << " " <<cnt << endl;
        cout << "Case " << kase++ <<
            ": average length between pages = " <<
            setprecision(3) << fixed << 1.0 * p / cnt << " clicks" << endl;
    }
}
