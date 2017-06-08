//2017-05-20-22.55
//???

#include <bits/stdc++.h>

using namespace std;

const int maxn = 10e4 + 10, maxm = 8;
int d[maxn][1 << maxm];
int a[maxn], n, st;
bool vis[maxn][1 << maxm];
vector<int> v[maxm + 1];
const int INF = 100000;

int dp(int i, int s, int x) {
    if (vis[i][s]) return d[i][s];
    vis[i][s] = 1;
    if (i > n) {
        if (s == ((1 << 8) - 1)) return d[i][s] = 0;
        return d[i][s] = -INF;
    }
    int cur = a[i];
    int re = -INF;
    if (!((s >> (a[i] - 1)) & 1)) {
        int p = lower_bound(v[cur].begin(), v[cur].end(), i) - v[cur].begin();
        if (p + x - 1 < v[cur].size()) {
            re = max(re, x + dp(v[cur][p + x - 1] + 1, (s | (1 << (cur - 1))), x));
        }
        if (p + x < v[cur].size()) {
            re = max(re, x + 1 + dp(v[cur][p + x] + 1, (s | (1 << (cur - 1))), x));
        }
    }
    re = max(re, dp(i + 1, s, x));
    return d[i][s] = re;
}
int cal(int x) {
    memset(vis, 0, sizeof vis);
    int ans = dp(1, 0, x);
    return ans;
}

int main() {
    cin >> n;
    st = (1 << 8) - 1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        v[a[i]].push_back(i);
        st &= (~(1 << (a[i] - 1)));
    }
    if (st != 0) {
        int ans = 0;
        for (int i = 0; i < 8; i++) {
            if (!((st >> i) & 1)) ans++;
        }
        cout << ans << endl;
        return 0;
    }
    int l = 1, r = n / 8 + 1;
    int ans = -INF;
    while (l < r) {
        int m = l + (r - l) / 2;
        int re = cal(m);
        ans = max(ans, re);
        if (re >= 0) l = m + 1;
        else r = m;
    }
    if (ans < 0) ans = 0;
    cout << ans << endl;
}
