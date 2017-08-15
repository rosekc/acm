//2017-07-30-15.14
//1006

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e4;
const int mod = 1e9 + 7;
int n, m;
int d[maxn][maxn];
int f(int i, int j) {
    if (d[i][j] != -1) return d[i][j];
    if (i == 1) {
        if (j <= 2) return d[i][j] = 1;
        return d[i][j] = (f(i, j - 1) + (2 * f(i, j - 2)) % mod) % mod;
    }
    int &ans = d[i][j] = 0;
    for (int k = j; k <= j + n - 1; k++) {
        ans += f(i - 1, k);
        ans %= mod;
    }
    return ans;
}

int main() {
    int wid = 10;
    while (cin >> n >> m) {
        memset(d, -1, sizeof d);
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= wid; j++) {
                printf("%-9d", f(i,j));
            }
            puts("");
        }
    }
}
