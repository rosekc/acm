//2017-04-30-01.32
//Uva 11400

#include <bits/stdc++.h>

using namespace std;

struct Node {
    int v, k, c, l;
    bool operator < (const Node& b) {
        return v < b.v;
    }
};

Node a[1010];
int dp[1010], s[1010];

int main() {
    int n;
    while (cin >> n && n) {
        s[0] = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i].v >> a[i].k >> a[i].c >> a[i].l;
        }
        sort(a + 1, a + 1 + n);
        for (int i = 1; i <= n; i++) {
            s[i] = s[i - 1] + a[i].l;
        }
        dp[1] = a[1].k + a[1].c * a[1].l;
        for (int i = 2; i <= n; i++) {
            dp[i] = 0x3f3f3f3f;
            for (int j = 0; j < i; j++) {
                dp[i] = min(dp[i], dp[j] + (s[i] - s[j]) * a[i].c + a[i].k);
            }
        }
        cout << dp[n] << endl;
    }
}
