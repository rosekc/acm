//2017-09-09-11.57
//A

#include <bits/stdc++.h>

using namespace std;

const int maxn = 60;
bool a[maxn][maxn], b[maxn][maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, n, m;
    bool first = 0;
    cin >> T;
    while (cin >> n >> m) {
        memset(a, 0, sizeof a);
        memset(b, 0, sizeof b);
        for (int i = 1; i <= n; i++) {
            int x, y;
            cin >> x >> y;
            a[x][y] = 1;
        }
        for (int i = 1; i <= m; i++) {
            int x, y;
            cin >> x >> y;
            b[x][y] = 1;
        }
        for (int i = 1; i <= n; i++) {
            for (int k = 1; k <= 50; k++) {
                for (int j = 1; j <= m; j++) {
                    if (a[i][j] && b[j][k]) {
                        cout << i << " " << k << endl;
                        break;
                    }
                }
            }
        }
        if (!first) cout << '\n';
        first = 0;
    }
}
