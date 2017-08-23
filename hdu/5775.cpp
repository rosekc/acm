//2017-08-23-16.00
//5775

#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int C[maxn], n;
int lowbit(int x) {
    return x&(-x);
}
int sum(int x) {
    int ret = 0;
    while (x > 0) {
        ret += C[x];
        x -= lowbit(x);
    }
    return ret;
}
void add(int x, int d) {
    while (x <= n) {
        C[x] += d; x += lowbit(x);
    }
}

int ans[maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T, t, kase = 1;
    cin >> T;
    while (T--) {
        memset(C, 0, sizeof C);
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> t;
            int d = abs(t - i);
            int r = max(t, t - sum(t - 1) + i - 1);
            int l = min(t, i);
            //cout << l << ' ' << r << endl;
            ans[t] = r - l;
            add(t, 1);
        }
        cout << "Case #" << kase++ << ":";
        for (int i = 1; i <= n; i++) {
            cout << ' ';
            cout << ans[i];
        }
        cout << endl;
    }
}
