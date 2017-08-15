//2017-08-08-13.45
//1008

#include <bits/stdc++.h>

using namespace std;

long long a[10000 + 10];
int ans[60];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T, m, n;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 0; i <= m; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            int j;
            for (j = 1; a[j] == 0; j++);
            ans[i] = j;
            for (int k = 0; k + j <= m; k++) {
                if (a[k] > 0) {
                    a[k + j] -= a[k];
                }
            }
        }
        bool first = 1;
        for (int i = 0; i < n; i++) {
            if (first) {
                cout << ans[i];
                first = 0;
            }else {
                cout << ' ' << ans[i];
            }
        }
        cout << endl;
    }
}
