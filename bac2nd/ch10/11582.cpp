//2017-08-26-22.31
//Uva 11582

#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 10;
int f[maxn][maxn * 6];
int p[maxn];
int pow_mod(unsigned long long a, unsigned long long n, int m) {
    if (n == 0) return 1;
    int x = pow_mod(a, n / 2, m);
    unsigned long long ans = 1ull * x * x % m;
    if (n % 2 == 1) ans = ans * (a % m) % m;
    return (int)ans;
}

int main() {
    for (int i = 2; i <= 1000; i++) {
        f[i][0] = 0;
        f[i][1] = 1;
        for (int j = 2;; j++) {
            f[i][j] = (f[i][j - 1] + f[i][j - 2]) % i;
            if (f[i][j] == 1 && f[i][j - 1] == 0) {
                p[i] = j - 1;
                break;
            }
        }
    }
    int T, n;
    unsigned long long a, b;
    cin >> T;
    while (T--) {
        cin >> a >> b >> n;
        if (a == 0 || n == 1) {
            puts("0");
            continue;
        }
        //cout << p[n] << endl;
        cout << f[n][pow_mod(a, b, p[n])] << endl;
    }
}
