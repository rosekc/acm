//2017-09-23-20.09
//F

#include <bits/stdc++.h>

using namespace std;

int a[1005], b[1005];
vector<int> ans;

int main() {
    int n, m;
    cin >> n >> m;
    if (m == 0) {
        cout << (n == 1 ? 1 : -1) << endl;
        return 0;
    }
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
    }
    for (int i = 1; i <= 100; i++) {
        bool ok = 1;
        for (int j = 0; j < m; j++) {
            if (!(a[j] <= b[j] * i && a[j] > (b[j] - 1) * i)) {
                ok = 0;
                break;
            }
        }
        if (ok) {
            ans.push_back(i);
        }
    }
    //cout << ans.size() <<endl;
    bool ok = 1;
    for (int i = 0; i < (int)ans.size() - 1; i++) {
        if ((n - 1) / ans[i] != (n - 1) / ans[i + 1]) {
            ok = 0;
            break;
        }
    }
    if ((int)ans.size() == 0) ok = 0;
    if (ok) cout << (n - 1) / ans[0] + 1 << endl;
    else cout << -1 << endl;
}
