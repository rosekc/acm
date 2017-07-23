//2017-07-15-12.02
//A

#include <bits/stdc++.h>

using namespace std;

long long a[20][20][20];
long long re[100], sum[100];
int n, q, x, y, z;

void cal(int i, int j, int k) {
    if (a[i][j][k] == 0) return;
    for (int ii = 0; ii <= 10; ii++) {
        for (int jj = 0; jj <= 10; jj++) {
            for (int kk = 0; kk <= 10; kk++) {
                if (ii == i && jj == j && k == kk) {
                    re[0] += (a[i][j][k] - 1) * (a[i][j][k]);
                    continue;
                }
                if (a[ii][jj][kk]) {
                    re[abs(i - ii) + abs(jj - j) + abs(k - kk)] += a[i][j][k] * a[ii][jj][kk];
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        memset(re, 0, sizeof re);
        memset(a, 0, sizeof a);
        cin >> n >> q;
        for (int i = 0; i < n; i++) {
            cin >> x >> y >> z;
            a[x][y][z]++;
        }
        for (int ii = 0; ii <= 10; ii++) {
            for (int jj = 0; jj <= 10; jj++) {
                for (int kk = 0; kk <= 10; kk++) {
                    cal(ii, jj, kk);
                }
            }
        }
        for (int i = 1; i <= 60; i++) {
            //cout << re[i - 1] << endl;
            sum[i] = sum[i - 1] + (re[i - 1] / 2);
            //cout << sum[i] << endl;
        }
        int t;
        while (q--) {
                //cout << q <<endl;
            cin >> t;
            if (t + 1 > 40) t = 40;
            cout << sum[t + 1] << endl;
        }
    }
}
