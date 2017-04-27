//2017-04-27-22.36
//Uva 116

#include <bits/stdc++.h>

using namespace std;

int d[15][110];
int dp[15][110];
int nextp[15][110];

const int INF = 0x3f3f3f3f;

int main() {
    int r, c;
    while (cin >> r >> c) {
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                cin >> d[i][j];
            }
        }
        int ans = INF;
        int first = 0;
        for (int j = c; j > 0; j--) {
            for (int i = 1; i <= r; i++) {
                if (j == c) dp[i][j] = d[i][j];
                else {
                    int row[] = {i, i - 1, i + 1};
                    if (i == 1) row[1] = r;
                    if (i == r) row[2] = 1;
                    sort(row, row + 3);
                    dp[i][j] = INF;
                    for (int k = 0; k < 3; k++) {
                        int v = dp[row[k]][j + 1] + d[i][j];
                        if (v < dp[i][j]) {
                            dp[i][j] = v;
                            nextp[i][j] = row[k];
                        }
                    }
                }
                if (j == 1 && dp[i][j] < ans) {
                    ans = dp[i][j];
                    first = i;
                }
            }
        }
        cout << first;
        for (int i = nextp[first][1], j = 2; j <= c; i = nextp[i][j++]) {
            cout << " " << i;
        }
        cout << '\n' << ans << '\n';
    }
}
