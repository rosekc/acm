//2017-04-21-23.50
//Uva 437

#include <bits/stdc++.h>

using namespace std;

int d[35][3], n, dp[35][3];

bool check(int i, int j, int i1, int j1) {
    int a[2], b[2];
    for (int p = 0, cur = 0; p < 3; p++) {
        if (p == j) continue;
        a[cur++] = d[i][p];
    }
    for (int p = 0, cur = 0; p < 3; p++) {
        if (p == j1) continue;
        b[cur++] = d[i1][p];
    }
    //printf("%d %d %d %d %d\n", i, j, i1, j1, a[0] > b[0] && a[1] > b[1]);
    return a[0] > b[0] && a[1] > b[1];
}

int cal(int i, int j) {
    int& ans = dp[i][j];
    //printf("%d %d\n", i, j);
    if (ans >= 0) return ans;
    ans = d[i][j];
    for (int i1 = 0; i1 < n; i1++) {
        for (int j1 = 0; j1 < 3; j1++) {
            if (check(i, j, i1, j1)) {
                //printf("ij%d %d\n", i1, j1);
                ans = max(ans, d[i][j] + cal(i1, j1));
            }

        }
    }
    //printf("%d %d %d\n", i, j, ans);
    return ans;
}

int main() {
    int kase = 0;
    while (cin >> n && n) {
        memset(dp, -1, sizeof dp);
        for (int i = 0; i < n; i++) {
            cin >> d[i][0] >> d[i][1] >> d[i][2];
            sort(d[i], d[i] + 3);
        }
        int ans = -1;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < 3; j++)
                ans = max(ans, cal(i, j));
        printf("Case %d: maximum height = %d\n", ++kase, ans);
    }
}
