//2017-07-29-01.36
//1003

#include <bits/stdc++.h>

using namespace std;

#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
const int maxn = 250000 + 100, mod = 1e9 + 7;
int a[maxn << 2], b[maxn];
void push_up(int rt) {
    a[rt] = max(a[rt << 1], a[rt << 1 | 1]);
}
void built(int l, int r, int rt) {
    if (l == r) {
        cin >> a[rt];
        a[rt] -= l;
        return;
    }
    int m = (l + r) >> 1;
    built(lson);
    built(rson);
    push_up(rt);
}
int query(int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R) {
        return a[rt];
    }
    int m = (l + r) >> 1;
    int ret = 0;
    if (L <= m) ret = max(ret, query(L, R, lson));
    if (R > m) ret = max(ret, query(L, R, rson));
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    int n;
    while (cin >> n) {
        built(1, n, 1);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        sort(b, b + n);
        int ans = 0;
        int maxb = -1;
        for (int i = 0; i < n; i++) {
            int nval = max(query(b[i], n, 1, n, 1), maxb);
            ans = (ans + nval) % mod;
            maxb = max(maxb, nval - n - i - 1);
        }
        cout << ans << endl;
    }
}
