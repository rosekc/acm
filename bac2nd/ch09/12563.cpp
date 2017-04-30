//2017-04-27-23.22
//Uva 12563

#include <bits/stdc++.h>

using namespace std;

const int maxt = 180 * 60 + 678;
const int maxn = 60;

struct Node {
    int t, cnt;
    bool operator < (const Node &b)const {
        if (cnt == b.cnt) {
            return t < b.t;
        }
        return cnt < b.cnt;
    }
};

int d[maxn];
Node dp[maxt][maxn];

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int T, kase = 1;
    cin >> T;
    while (T--) {
        int n, t, re;
        cin >> n >> t;
        for (int i = 1; i <= n; i++) {
            cin >> d[i];
        }
        if (t > maxt) {
            int re = 0;
            for (int i = 1; i <= n; i++) {
                re += d[i];
            }
            printf("Case %d: %d %d\n", kase++, n + 1, re + 678);
            continue;
        }
        for (int i = 0; i < t; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = {0, 0};
                    continue;
                }
                dp[i][j] = dp[i][j - 1];
                if (d[j] <= i) dp[i][j] = max(dp[i][j], {dp[i - d[j]][j - 1].t + d[j], dp[i - d[j]][j - 1].cnt + 1});
            }
        }
        printf("Case %d: %d %d\n", kase++, dp[t - 1][n].cnt + 1, dp[t - 1][n].t + 678);
    }
}
