//2017-08-26-21.11
//D

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, st, x, val, nxt;
    cin >> n >> st >> x;
    if (n <= 1999) {
        int ans = -1;
        for (int i = 1; i <= n; i++) {
            cout << "? " << i << endl;
            cin >> val >> nxt;
            if (val >= x) {
                ans = min(val, ans == -1 ? val + 1 : ans);
            }
        }
        cout << "! " << ans << endl;
        return 0;
    }
    int ans = -1;
    int tnxt, tval;
    default_random_engine ran(time(0));
    uniform_int_distribution<int> dis(1, n);
    int p = 0;
    cout << "? " << st << endl;
    cin >> val >> nxt;
    if (val >= x) {
        cout << "! " << val << endl;
        return 0;
    }
    tval = val;
    tnxt = nxt;
    p++;
    for (; p <= 1000; p++) {
        cout << "? " << dis(ran) << endl;
        cin >> val >> nxt;
        if (val < x && tval < val) {
            tval = val;
            tnxt = nxt;
        }
        if (val >= x) {
            ans = min(val, ans == -1 ? val + 1 : ans);
        }
    }
    while (p < 1999) {
        cout << "? " << tnxt << endl;
        cin >> val >> nxt;
        if (val >= x) {
            cout << "! " << val << endl;
            return 0;
        }
        if (nxt == -1) {
            break;
        }
        tnxt = nxt;
        p++;
    }
    cout << "! " << ans <<endl;
}
