//2017-11-16-14.00
//LA3938

#include <bits/stdc++.h>

using namespace std;
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
const int maxn = 55555;
pair<long long, long long> max_sub[maxn << 2];
long long max_pre[maxn << 2], max_suf[maxn << 2];
long long sum_pre[maxn];
long long sum(int L, int R) {
    return sum_pre[R] - sum_pre[L - 1];
}
typedef pair<long long, long long> pll;
pll max(pll a, pll b) {
    long long v1 = sum(a.first, a.second), v2 = sum(b.first, b.second);
    if (v1 == v2) {
        if (a < b) return a;
        else return b;
    }
    if (v1 > v2) {
        return a;
    }
    return b;
}

void PushUP(int rt, int l, int r) {
    max_sub[rt] = max(max_sub[rt * 2], max(
        max_sub[rt * 2 + 1], {max_suf[rt * 2], max_pre[rt*2 + 1]});
    max_pre[rt] = max({l, max_pre[rt * 2]}, {l, max_pre[rt*2 + 1]}).second;
    max_suf[rt] = max({max_suf[rt*2], r}, {max_suf[rt*2 + 1], r}).first;
}
void build(int l, int r, int rt) {
    if (l == r) {
        max_sub[rt] = {l, r};
        max_pre[rt] = max_suf[rt] = l;
        return ;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    PushUP(rt, l, r);
}
pll query_pre(int L, int R, int l, int r, int rt) {
    if (max_pre[rt] <= R) {
        return {L, max_pre[rt]};
    }
    int m = l + (r - l) / 2;
    if (R <= m) return query_pre(lson);
    
}
pll query(int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R) {
        return max_sub[rt];
    }
    int m = (l + r) >> 1;
    int ret = 0;
    if (R <= m) return query(l, m, lson);
    if (L > m) return query(m + 1, r, rson);
    pll p1 = query_pre
    pll p2 = ;
    pll p3 = max(query(l, m, lson), query(m + 1, r, rson));
    return max({p1.}, p3);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    int kase = 0;
    while (cin >> n >> m) {
        for (int i = 1; i <= n; i++) {
            cin >> sum_pre[i];
            sum_pre[i] += sum_pre[i - 1];
        }
        built(1, n, 1);
        while (m--) {
            int l, r;
            cin >> l >> r;

        }
        cout << "Case 1:\n";
    }
}
