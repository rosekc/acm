//2017-04-23-16.46
//F

#include <bits/stdc++.h>

using namespace std;
const int mod = 10e9 + 7;
int main()
{
    int n, m, k;
    while (cin >> n >> m >> k) {
        int l, r;
        int re = k;
        for (int i = 0; i < m; i++) {
            cin >> l >> r;
            for (int i = 1; i <= n; i++) {
                if (i == l || i == r) continue;
                int p = k;
                if (i == (l + 1) % n || i == (l - 1) % n) p--;
            }
        }
    }
}
