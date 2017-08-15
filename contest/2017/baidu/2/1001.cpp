//2017-08-12-13.55
//1001

#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int x;
        cin >> x;
        int ans = 0;
        for (int i = 1; i <= sqrt(x - 1); i++) {
            if ((x - 1) % i == 0) {
                if ((x - 1) / i == i) {
                    ans++;
                }else ans += 2;
            }
        }
        cout << ans << endl;
    }
}
