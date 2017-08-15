//2017-08-12-22.37
//A

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k, a;
    cin >> n >> k;
    int cnt1, cnt2;
    cnt1 = cnt2 = 0;
    int ans = -1;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        cnt1 += a;
        if (cnt1 > 8) {
            cnt1 -= 8;
            cnt2 += 8;
        } else {
            cnt2 += cnt1;
            cnt1 = 0;
        }
        if (ans == -1 && cnt2 >= k) {
            ans = i;
        }
    }
    if (ans != -1) {
        cout << ans << endl;
    } else {
        cout << "-1" << endl;
    }
}
