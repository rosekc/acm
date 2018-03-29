// 2018-03-29 15:52:58

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2000 + 100;
int a[MAXN][MAXN];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    int x, y, w;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> y >> w;
        a[++x][++y] += w;
    }
    for (int i = 1; i < MAXN; i++) {
        for (int j = 1; j < MAXN; j++) {
            a[i][j] += a[i][j - 1];
        }
    }
    for (int j = 1; j < MAXN; j++) {
        for (int i = 1; i < MAXN; i++) {
            a[i][j] += a[i - 1][j];
        }
    }
    cin >> q;
    while (q--) {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        y2++;x2++;
        cout << a[x2][y2] + a[x1][y1] - a[x1][y2] - a[x2][y1] << endl;
    }
}