//2017-07-11-11.51
//Uva 437

#include <bits/stdc++.h>

using namespace std;

int n;
int d[35][3];
int a[35][3];

bool check(int i1, int j1, int i2, int j2) {
    int t1[2], t2[2];
    for (int i = 0, cur = 0; i < 3; i++) {
        if (i == j1) continue;
        t1[cur++] = a[i1][i];
    }
    for (int i = 0, cur = 0; i < 3; i++) {
        if (i == j2) continue;
        t2[cur++] = a[i2][i];
    }
    return (t1[0] > t2[0] && t1[1] > t2[1]);
}

int dp(int i, int j) {
    if (d[i][j] >= 0) return d[i][j];
    int ans = a[i][j];
    for (int i1 = 0; i1 < n; i1++) {
        for (int j1 = 0; j1 < 3; j1++) {
            if (check(i, j, i1, j1)) {
                //cout << i << " " << j << endl;
                ans = max(ans, dp(i1, j1) + a[i][j]);
            }
        }
    }
    //cout << ans << endl;
    return d[i][j] = ans;
}

int main() {
    int kase = 1;
    while (cin >> n && n) {
        memset(d, -1, sizeof d);
        for (int i = 0; i < n; i++) {
            cin >> a[i][0] >> a[i][1] >> a[i][2];
            sort(a[i], a[i] + 3);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                ans = max(ans, dp(i, j));
            }
        }
        printf("Case %d: maximum height = %d\n",
               kase++, ans);
    }
}
