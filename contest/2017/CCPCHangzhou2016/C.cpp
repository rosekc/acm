//2017-10-28-18.04
//C

#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-9;
const int maxn = 1e5;
int a[maxn];
int sgn(double a) {
    if (abs(a) < eps) return 0;
    if (a < 0) return -1;
    else return 1;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, kase = 0, n;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        long long ans = 1;
        int last_t = 1;
        int last_s = a[n] - a[n - 1];
        for (int i = n - 1; i > 0; i--) {
            int s = a[i] - a[i - 1];
            int t = floor(s * last_t * 1.0 / last_s) - 1;
            while (s * last_t > last_s * t) {
                t++;
            }
            ans += t;
            last_t = t;
            last_s = s;
        }
        cout << "Case #" << ++kase << ": " << ans << endl;
    }
}
