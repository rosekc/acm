//2017-07-15-13.40
//B

#include <bits/stdc++.h>

using namespace std;
long long pow_mod(long long a, long long n, long long m) {
    if (n == 0) return 1;
    int x = pow_mod(a, n / 2, m);
    long long ans = (long long)x * x % m;
    if (n % 2 == 1) ans = ans * a % m;
    return (int)ans;
}
int main() {
    long long T, n, k, p, ans;
    cin >> T;
    while (T--) {
        cin >> n >> k >> p;
        ans = 0;
        for (int i = 1; i <= n; i++) {
            if (i % p == 0) continue;
            ans += pow_mod(i, k, p);
            ans %= p;
        }
        cout << ans << endl;
    }
}
