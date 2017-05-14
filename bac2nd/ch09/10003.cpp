//2017-05-13-23.53
//10003

#include <bits/stdc++.h>

using namespace std;

const int maxl = 1010, maxn = 80;
int l, n;
int a[maxn], d[maxn][maxn];

int dp(int i, int j) {
    //cout << i << j << endl;
    if (d[i][j] != -1) return d[i][j];
    if (i == j - 1) return d[i][j] = 0;
    int re = 10e9;
    for (int k = i + 1; k < j; k++) {
        re = min(re, dp(i, k) + dp(k, j) + a[j] - a[i]);
    }
    return d[i][j] = re;
}

int main() {
    while (cin >> l && l) {
        cin >> n;
        memset(d, -1, sizeof d);
        a[1] = 0;
        for (int i = 2; i <= n + 1; i++) {
            cin >> a[i];
        }
        a[n + 2] = l;
        cout << "The minimum cutting is " << dp(1, n + 2) << "." << endl;
    }
}
