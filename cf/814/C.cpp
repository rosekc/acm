//2017-06-07-20.58
//C

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1600;
int n, q, m;
char s[maxn], c[5];
int vis[maxn][26];
int sum[maxn][26];
int solve() {
    int re = 0;
    int ed = 1;
    int cur = c[0] - 'a';
    for (int i = 1; i <= n - m + 1; i++) {
        while (ed <= n && sum[ed][cur] - sum[i - 1][cur] <= m) ed++;
        re = max(re, ed - i);
    }
    return re;
}
int main() {
    cin >> n >> (s + 1) >> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 26; j++) {
            sum[i][j] = sum[i - 1][j] + (s[i] != 'a' + j);
        }
    }
    while (q--) {
        scanf("%d%s", &m, c);
        if (vis[m][c[0] - 'a']) {
            printf("%d\n", vis[m][c[0] - 'a']);
            continue;
        }
        vis[m][c[0] - 'a'] = solve();
        printf("%d\n", vis[m][c[0] - 'a']);
    }
}
