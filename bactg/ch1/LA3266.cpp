//2017-10-23-20.28
//LA3266

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e3 + 100;
int a[maxn], b[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while (cin >> n && n) {
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        sort(a, a + n);
        sort(b, b + n);
        int al, bl, ar, br, ans;
        ans = al = bl = 0;
        ar = br = n - 1;
        while (n--) {
            if (a[al] > b[bl]) {
                ans++;
                al++;
                bl++;
            }else if (a[ar] > b[br]) {
                ans++;
                ar--;
                br--;
            }else if (a[al] < b[br]) {
                ans--;
                al++;
                br--;
            }else {
                al++;
                br--;
            }
        }
        cout << ans * 200 << '\n';
    }
}
