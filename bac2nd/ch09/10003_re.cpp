//2017-07-13-13.30
//Uva 10003

#include <bits/stdc++.h>

using namespace std;

int a[55], d[55][55], n, l;

int dp(int i, int j) {
//    cout << i << " " << j << endl;
    if (d[i][j] != -1) return d[i][j];
    if (i == j - 1) return d[i][j] = 0;
    int &ans = d[i][j] = 0x3f3f3f3f;
    for (int p = i + 1; p < j; p++) {
        ans = min(ans, dp(i, p) + dp(p, j) + a[j] - a[i]);
    }
    return ans;
}

int main() {
    while (cin >> l && l) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        a[n + 1] = l;
        memset(d,  -1, sizeof(d));
        printf("The minimum cutting is %d.\n", dp(0, n + 1));
    }
}
