#include <bits/stdc++.h>

using namespace std;

const int maxn = 55, maxt = 205, INF = 0x3f3f3f3f;
int d[maxn][maxt], a[maxn];
bool havetrain[maxn][maxt][2], vis[maxn][maxt];
int n, t;

int dp(int i, int j) {
    if (vis[i][j]) return d[i][j];
    vis[i][j] = 1;
    if (j == t) {
        if (i == n) return d[i][j] = 0;
        return d[i][j] = INF;
    }
    if (j > t) return d[i][j] = INF;
    int ans = dp(i, j + 1) + 1;
    if (havetrain[i][j][0] && i != n) {
        ans = min(ans, dp(i + 1, j + a[i]));
    }
    if (havetrain[i][j][1] && i != 1) {
        ans = min(ans, dp(i - 1, j + a[i - 1]));
    }
    return d[i][j] = ans;
}

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int kase = 1;
    while (cin >> n && n) {
        memset(havetrain, 0, sizeof havetrain);
        memset(vis, 0, sizeof vis);
        cin >> t;
        for (int i = 1; i < n; i++) {
            cin >> a[i];
        }
        int m1, t1;
        cin >> m1;
        for (int i = 0; i < m1; i++) {
            cin >> t1;
            for (int j = 1; j <= n && t1 <= t; j++) {
                havetrain[j][t1][0] = 1;
                t1 += a[j];
            }
        }
        cin >> m1;
        for (int i = 0; i < m1; i++) {
            cin >> t1;
            for (int j = n; j >= 1 && t1 <= t; j--) {
                havetrain[j][t1][1] = 1;
                t1 += a[j - 1];
            }
        }
//        for (int i = 1; i <= n; i++) {
//            for (int j = 0; j <= t; j++) {
//                cout << havetrain[i][j][0] << " ";
//            }
//            cout << endl;
//        }
        dp(1, 0);
        cout << "Case Number " << kase++ << ": ";
        if (vis[n][t]) cout << dp(1, 0) << endl;
        else puts("impossible");
    }
}
