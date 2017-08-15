#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 100;
const int maxm = 1e3 + 100;
int a[maxn], b[maxn], k[maxm], p[maxm];
long long d[20][1000 + 10];
const long long INF = (1ll << 60);
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m, n;
    while (cin >> n >> m) {
        for (int i = 1; i <= n; i++) {
            cin >> a[i] >> b[i];
        }
        for (int i = 1; i <= m; i++) {
            cin >> k[i] >> p[i];
        }
        for (int i = 0; i <= 10; i++) {
            for (int j = 0; j <= 1000; j++) {
                if (j == 0) {
                    d[i][j] = 0;
                }else d[i][j] = INF;
            }
        }
        for (int i = 0; i <= 10; i++) {
            for (int j = 1; j <= 1000; j++) {
                
                for (int x = 1; x <= m; x++) {
                    if (p[x] <= i) continue;
                    int y = j - p[x] + i < 0 ? 0 : j - p[x] + i;
                    d[i][j] = min(d[i][j], d[i][y] + k[x]);
                }
            }
        }
        // for (int i = 0; i <= 10; i++) {
        //     for (int j = 0; j <= 10; j++) {
        //         cout << d[i][j] << ' ';
        //     }
        //     cout << endl;
        // }
        long long ans = 0;
        bool fail = 0;
        for (int i = 1; i <= n; i++) {
            if (d[b[i]][a[i]] == INF) {
                fail = 1;
                cout << "-1\n";
                break;
            }
            ans += d[b[i]][a[i]];
        }
        if (!fail) cout << ans << '\n';
    }
}