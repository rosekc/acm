// 2017-11-17 23:19:55
// HDU1166

#include <bits/stdc++.h>
using namespace std;
#define lson l, m, rt * 2
#define rson m + 1, r, rt * 2 + 1
const int maxn = 1e5 + 100;
int sum[maxn * 4];
void push_up(int rt) {
    sum[rt] = sum[rt * 2] + sum[rt * 2 + 1];
}
void build(int l, int r, int rt) {
    if (l == r) {
        cin >> sum[rt];
        return;
    }
    int m = (l + r) / 2;
    build(lson);
    build(rson);
    push_up(rt);
}

int p, v;
void update(int l, int r, int rt) {
    if (l == r) {
        sum[rt] += v;
        return;
    }
    int m = (l + r) / 2;
    if (p <= m) update(lson);
    else update(rson);
    push_up(rt);
}
int L, R;
int query(int l, int r, int rt) {
    if (L <= l && r <= R) {
        return sum[rt];
    }
    int m = (l + r) / 2;
    int ans = 0;
    if (L <= m) ans += query(lson);
    if (m < R) ans += query(rson);
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    int kase = 1;
    while (T--) {
        int n;
        cin >> n;
        cout << "Case " << kase++ << ":\n";
        build(1, n, 1);
        string cmd;
        while (cin >> cmd && cmd[0] != 'E') {
            if (cmd[0] == 'Q') {
                cin >> L >> R;
                cout << query(1, n, 1) << endl;
            }else if (cmd[0] == 'A') {
                cin >> p >> v;
                update(1, n, 1);
            }else if (cmd[0] == 'S') {
                cin >> p >> v;
                v = -v;
                update(1, n, 1);
            }
        }
    }
}