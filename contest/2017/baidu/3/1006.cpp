//2017-08-13-14.29
//1006

#include <bits/stdc++.h>

using namespace std;

const int maxn = 100000 + 10;

struct St {
    int l, r;
    bool operator < (const St & b)const & {
        return l < b.l;
    }
};

St a[maxn];

int n, m, l, r;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> n >> m) {
        for (int i = 1; i <= n; ++i)
            cin >> a[i].l >> a[i].r;
        sort(a + 1, a + 1 + n);
        int tm = n;
        n = 0;
        for (int i = 1; i <= tm; ++i) {
            if (i != 1 && a[i].l <= a[n].r) {
                a[n].r = max(a[n].r, a[i].r);
            } else {
                a[++n].l = a[i].l;
                a[n].r = a[i].r;
            }
        }
        l = 1;
        int cur = 0;
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (i != 1) {
                cur += a[i].l - a[i - 1].r - 1;
            }
            while (i != 1 && cur > m) {
                cur -= a[l + 1].l - a[l].r - 1;
                ++l;
            }
            ans = max(ans, a[i].r - a[l].l + 1 + m - cur);
        }
        cout << ans << endl;
    }
}
