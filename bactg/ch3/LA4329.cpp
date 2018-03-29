//2017-10-26-23.12
//LA4329

#include <bits/stdc++.h>

using namespace std;

inline int lowbit(int x) {
    return x & -x;
}

struct BIT {
    const static int n = 1e5 + 100;
    int C[n];

    int init() {
        memset(C, 0, sizeof(C));
    }

    // 计算A[1]+A[2]+...+A[x] (x<=n)
    int sum(int x) {
        int ret = 0;
        while (x > 0) {
            ret += C[x];
            x -= lowbit(x);
        }
        return ret;
    }

    // A[x] += d (1<=x<=n)
    void add(int x, int d) {
        while (x <= n) {
            C[x] += d;
            x += lowbit(x);
        }
    }
};

const int maxn = 2e4 + 100;
long long a[maxn], c[maxn], d[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, T;
    cin >> T;
    BIT bt;
    while (T--) {
        cin >> n;
        memset(c, 0, sizeof(c));
        memset(d, 0, sizeof d);
        for (int i = 1; i <= n; i++) cin >> a[i];
        bt.init();
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            c[i] = bt.sum(a[i] - 1);
            bt.add(a[i], 1);
        }
        bt.init();
        for (int i = n; i >= 1; i--) {
            d[i] = bt.sum(a[i] - 1);
            bt.add(a[i], 1);
            ans += (1ll * c[i] * (n - i - d[i]) + (i - 1 - c[i]) * 1LL * d[i]);
        }
        cout << ans << endl;
    }
}
