// 2017-11-17 15:01:26
// Uva11078

#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 100;
int a[maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, t, T;
    cin >> T;
    while (T--) {
        cin >> n;
        int mxc = -INF, ans = -INF;
        for (int i = 0; i < n; i++) {
             cin >> t;
             if (i != 0) ans = max(ans, mxc - t);
             mxc = max(t, mxc);
        }
        cout << ans << endl;
    }
}