// 2017-11-17 23:58:34
// HDU1754

#include <bits/stdc++.h>
using namespace std;
#define lson l, m, rt * 2
#define rson m + 1, r, rt * 2 + 1
const int maxn = 200000 + 20;;
int maxv[maxn * 4];
void push_up(int rt) {
    maxv[rt] = max(maxv[rt * 2], maxv[rt * 2 + 1]);
}
void build(int l, int r, int rt) {
    if (l == r) {
        scanf("%d", &maxv[rt]);
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
        maxv[rt] = v;
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
        return maxv[rt];
    }
    int m = (l + r) / 2;
    int ans = -0x3f3f3f3f;
    if (L <= m) ans = max(query(lson), ans);
    if (m < R) ans = max(query(rson), ans);
    return ans;
}
int main() {
    int n, q;
    char cmd[10];
    while (scanf("%d%d", &n, &q) != EOF) {
        build(1, n, 1);
        while (q--) {
            scanf("%s", cmd);
            if (cmd[0] == 'Q') {
                scanf("%d%d", &L, &R);
                cout << query(1, n, 1) << endl;
            }else {
                scanf("%d%d", &p, &v);
                update(1, n, 1);
            }
        }
    }
}