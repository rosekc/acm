//2017-07-31-20.50
//1003

#include <bits/stdc++.h>

using namespace std;

const int maxn = 200010;
struct way{int po, next};
way e[2 * maxn];
int c[maxn], p[maxn], cur[maxn], fa[maxn], s[maxn], alo[maxn], blo[maxn];
int n, len;

void add(int x, int y) {
    e[++len] = {y, x};
    p[x] = len;
}

void dfs(int x) {
    s[x] = 1;
    int pre = cur[c[x]];
    cur[c[x]] = x;
    for (int i = p[x]; i; i = e[i].next) {
        int y = e[i].po;
        if (fa[x] != y) {
            blo[x] = 0;
            fa[y] = x;
            dfs(y);
            s[x] += s[y];
            ans -= 1ll * (s[y] - blo[x]) * (s[y] - blo[x] - 1) / 2;
        }
    }
    if (pre) blo[pre] += s[x];
    else alo[c[x]] += s[x];
    cur[c[x]] = pre;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int kase = 1;
    while (cin >> n) {
        len = 0;
        for (int i = 1; i <= n; i++) cin >> c[i];
        for (int i = 1; i < n; i++) {
            int x, y;
            cin >> x >> y;
            add(x, y);
            add(y, x);
        }
        ans = 1ll * n * (n - 1) * n / 2;
        dfs(1);
        for (int i = 1; i <= n; i++) {
            ans -= 1ll * (n - alo[i]) * (n - alo[i] - 1) / 2;
            blo[i] = cur[i] = alo[i] = p[i] = 0;
        }
        printf("");
    }
}
