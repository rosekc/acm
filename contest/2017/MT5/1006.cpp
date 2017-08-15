//2017-08-08-12.38
//1006

#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        long long n, m;
        cin >> n >> m;
        long long cnt = n * (n - 1) / 2;
        long long ans;
        if (m > cnt) {
            ans = cnt * 2;
        }else if (m >= n - 1) {
            ans = (m + (cnt - m) * 2) * 2;
        }else {
            ans = (m + m * (m - 1) + (cnt - m - m * (m - 1) / 2) * n) * 2;
        }
        cout << ans  << endl;
    }
}
