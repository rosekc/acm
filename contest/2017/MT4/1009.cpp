#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, n, t;
    cin >> T;
    while (T--) {
        cin >> n;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cin >> t;
            if (t % 2) cnt++;
        }
        if (cnt > n - cnt) {
            cout << "2 1\n";
        } else cout << "2 0\n";
    }
}
