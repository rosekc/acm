//2017-07-31-23.13
//C

#include <bits/stdc++.h>

using namespace std;
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
const int maxn = 1e3;

struct tree {
    int C[maxn][maxn];
    int lowbit(int x) {
        return x & (-x);
    }
    void add(int i, int j, int d) {
        //C[i][j] += d;
        for (int x = i; x < maxn; x += lowbit(x)) {
            for (int y = j; y < maxn; y += lowbit(y)) {
                C[x][y] += d;
            }
        }
    }
    int sum(int i, int j) {
        int ret = 0;
        for (int x = i; x > 0; x -= lowbit(x)) {
            for (int y = j; y > 0; y -= lowbit(y)) {
                ret += C[x][y];
            }
        }
        return ret;
    }
};
tree a[15];
int cnt[15];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q, c, x, y, s;
    cin >> n >> q >> c;
    while (n--) {
        cin >> x >> y >> s;
        a[s].add(x, y, 1);
    }

    int t, x1, y1, x2, y2;
    while (q--) {
        int ans = 0;
        cin >> t >> x1 >> y1 >> x2 >> y2;
        for (int i = 0; i <= c; i++) {
            cnt[i] = a[i].sum(x2, y2);
            if (x1 > 0 && y1 > 0) cnt[i] += a[i].sum(x1 - 1, y1 - 1);
            if (x1 > 0) cnt[i] -= a[i].sum(x1 - 1, y2);
            if (y1 > 0) cnt[i] -= a[i].sum(x2, y1 - 1);
            //cout << a[i].sum(x2, y2) << " " << a[i].sum(x1 - 1, y1 - 1) << " " << a[i].sum(x1 - 1, y2) <<  " " << a[i].sum(x2, y1  - 1) << endl;
            //cout << i << " " << cnt[i] << endl;;
            ans += ((i + t) % (c + 1)) * cnt[i];
        }
        cout << ans << endl;
    }
}
