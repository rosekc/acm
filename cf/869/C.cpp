//2017-10-07-17.24
//C

#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e3 + 100;
const int mod = 998244353;
long long d[maxn][maxn];

int main() {
    for (int i = 0; i < maxn; i++) {
        d[i][0] = d[0][i] = 1;
    }
    for (int i = 1; i < maxn; i++) {
        for (int j = 1; j < maxn; j++) {
            d[i][j] = d[i - 1][j] + j * d[i - 1][j - 1] % mod;
            d[i][j] %= mod;
        }
    }
    int a, b, c;
    cin >> a >> b >> c;
    cout << d[a][b] * d[a][c] % mod * d[b][c] % mod << endl;
}
