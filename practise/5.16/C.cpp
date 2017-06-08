//2017-05-19-22.44
//???

#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 20;
int a[maxn];

int main() {
    int ans = 0, n, s, t;
    cin >> n >> s;
    for (int i = 1; i <= n; i++) {
        cin >> t;
        if (i == s && t != 0) {
            ans++;
            a[0]++;
        }else a[t]++;
    }
    int cur = n, cnt0;
    for (int i = 0; i < n; i++) {
        cur -= a[i];
        if (i == 0) {
            ans += (a[0] - 1);
            cnt0 = a[0] - 1;
        }else if (a[i] == 0 && --cnt0 < 0) {ans++; cur--;}
        //cout << ans << endl;
        if (cur <= 0) break;
    }
    cout << ans << endl;
}
