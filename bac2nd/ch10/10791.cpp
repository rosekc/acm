//2017-08-27-21.04
//Uva 10791

#include <bits/stdc++.h>
using namespace std;

long long cal(long long n) {
    if (n == 1) return 2;
    long long ans = 0;
    int cnt = 0;
    int lim = sqrt(n + .5);
    for (int i = 2; i <= lim; i++) {
        if (n % i == 0) {
            cnt++;
            long long t = 1;
            while (n % i == 0) {
                n /= i;
                t *= i;
            }
            ans += t;
            //cout << n << endl;
            //cout << ans << endl;
            if (n == 1) break;
        }
    }
    if (n != 1) {
        ans += n;
        cnt++;
    }
    if (cnt == 1) ans++;
    return ans;
}

int main() {
    int kase = 1;
    long long n;
    while (cin >> n && n) {
        cout << "Case " << kase++ << ": ";
        //cal(n);
        cout << cal(n) << endl;
    }
}
