//2017-08-12-22.59
//B

#include <bits/stdc++.h>

using namespace std;

int a[10000 + 10];

int main() {
    int n, k;
    cin >> n >> k;
    int cnt1 = 2 * n;
    for (int i = 1; i <= k; i++) {
        cin >> a[i];
        //cout << a[i] << " " << cnt << endl;
        if (cnt1 * 2 > a[i]) {
            cnt1 -= a[i] / 2;
            a[i] = a[i] - (a[i] / 2) * 2;
        } else {
            a[i] -= cnt1 * 2;
            cnt1 = 0;
        }
        //cout << a[i] << " " << cnt << endl;
    }
    sort(a + 1, a + k + 1);;
    if (a[k] == 0) {
        cout << "YES" << endl;
        return 0;
    }
    int cnt2 = n;
    for (int i = 1; i <= k; i++) {
        //cout << a[i] << " " << cnt << endl;
        if (cnt2 * 4 > a[i]) {
            cnt2 -= a[i] / 4;
            a[i] = a[i] - (a[i] / 4) * 4;
        } else {
            a[i] -= cnt2 * 4;
            cnt2 = 0;
        }
        //cout << a[i] << " " << cnt << endl;
        if (cnt2 * 3 > a[i]) {
            cnt2 -= a[i] / 3;
            a[i] = a[i] - (a[i] / 3) * 3;
        } else {
            a[i] -= cnt2 * 3;
            cnt2 = 0;
        }
    }
    sort(a + 1, a + k + 1);
    //cout << a[2] << endl;
    if (a[k] == 0) {
        cout << "YES" << endl;
        return 0;
    }
    int p1 = lower_bound(a + 1, a + k + 1, 1) - a;
    int p2 = upper_bound(a + 1, a + k + 1, 1) - a;
    int p3 = upper_bound(a + 1, a + k + 1, 2) - a;
    int c1 = p2 - p1;
    int c2 = p3 - p2;
    c1 -= cnt1;
    cnt2 -= min(c1, c2);
    if (c1 > c2) {
        c1 -= c2;
        c2 = 0;
    } else {
        c2 -= c1;
        c1 = 0;
    }
    cnt2 -= (c1 + c2);
    if (cnt2 >= 0) {
        cout << "YES" << endl;
    }else {
        cout << "NO" << endl;
    }
}
