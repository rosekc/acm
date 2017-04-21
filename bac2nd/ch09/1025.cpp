//2017-04-21-23.03
//Uva 1025

#include <bits/stdc++.h>

using namespace std;

const int maxn = 55, maxt = 205, INF = 0x3f3f3f3f;
int n, t, d[maxn], dp[maxt][maxn], m, tmp, kase = 0;
bool has_train[maxt][maxn][2];

int main() {
    while (cin >> n && n) {
        cin >> t;
        memset(has_train, 0, sizeof has_train);
        for (int i = 1; i < n; i++) {
            cin >> d[i];
        }
        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> tmp;
            has_train[tmp][1][0] = 1;
            for (int j = 1; j < n; j++) {
                tmp += d[j];
                if (tmp > t) break;
                has_train[tmp][j + 1][0] = 1;
            }
        }
        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> tmp;
            has_train[tmp][n][1] = 1;
            for (int j = n - 1; j >= 1; j--) {
                tmp += d[j];
                if (tmp > t) break;
                has_train[tmp][j][1] = 1;
            }
        }
        for (int i = 1; i <= n - 1; i++) {
            dp[t][i] = INF;
        }
        dp[t][n] = 0;
        for (int i = t - 1; i >= 0; i--) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = dp[i + 1][j] + 1;
                if (j < n && has_train[i][j][0] && i + d[j] <= t) {
                    dp[i][j] = min(dp[i][j], dp[i + d[j]][j + 1]);
                }
                if (j > 1 && has_train[i][j][1] && i + d[j - 1] <= t) {
                    dp[i][j] = min(dp[i][j], dp[i + d[j - 1]][j - 1]);
                }
            }
        }
        cout << "Case Number " << ++kase << ": ";
        if (dp[0][1] >= INF) puts("impossible");
        else printf("%d\n", dp[0][1]);
    }
}
