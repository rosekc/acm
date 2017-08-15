//2017-08-13-14.13
//1001

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1010;
int c[maxn][maxn];
const int mod = 1e9 + 7;

int main() {
    for (int i = 1; i <= 1000; i++) {
        c[i][0] = c[i][i] = 1;
    }
    for (int i = 2; i <= 1000; i++) {
        for (int j = 1; j <= 1000; j++) {
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
        }
    }
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        cout << c[max(n, m)][min(n, m)] << endl;
    }
}
