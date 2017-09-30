//2017-09-10-12.49
//1002

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    while (cin >> n >> k) {
        if (n <= 2) {
            cout << n << endl;
            continue;
        }
        int ans = 0;
        for (int i = 1; i <= k; i++) {
            for (int j = i; j <= n + 1 - i; j++) {
                ans += 1;
            }
        }
        cout << ans << endl;
    }
}
