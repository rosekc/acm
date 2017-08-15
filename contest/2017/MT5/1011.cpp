//2017-08-08-12.13
//1011

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 100;
int a[maxn];

int main() {
    int n, k, T;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a + n);
        int ans = 1;
        for (int i = n - 1; i > 0; i--) {
            if (a[i] - a[i - 1] > k) {
                break;
            }
            ans++;
        }
        cout << ans << endl;
    }
}
