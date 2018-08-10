#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;
int a[26][maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T, kase = 1;
    cin >> T;
    while (T--) {
        int n, q;
        cin >> n >> q;
        string in;
        cin >> in;
        for (int i = 0; i < 26; i++) a[i][0] = 0;
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j + 1] = a[i][j] + ('A' + i == in[j]);
                //cout << a[j][i + 1] << " ";
            }
           //cout << endl;
        }
        cout << "Case #" << kase++ << ":" << endl;
        while (q--) {
            int l, r;
            cin >> l >> r;
            int ans;
            for (int i = 0; i < 26; i++) {
                ans = a[i][r] - a[i][l - 1];
                if (ans) break;
            }
            cout << ans << endl;
        }
    }
}