// 2017-11-21 20:31:33
// A

#include <bits/stdc++.h>
using namespace std;
int a[4], b[4];
int f[][4] = {
    {0, 1, 2, 3},
    {2, 0, 3, 1},
    {3, 2, 1, 0},
    {1, 3, 0, 2}
};

int main() {
    int T, kase = 1;
    cin >> T;
    while (T--) {
        for (int i = 0; i < 4; i++) cin >> a[i];
        for (int i = 0; i < 4; i++) cin >> b[i];
        bool ok;
        for (int i = 0; i < 4; i++) {
            ok = 1;
            for (int j = 0; j < 4; j++) {
                if (a[f[i][j]] != b[j]) {
                    ok = 0;
                    break;
                }
            }
            if (ok) break;
        }
        cout << "Case #" << kase++ << ": ";
        if (ok) cout << "POSSIBLE" << endl;
        else cout << "IMPOSSIBLE" << endl;
    }
}