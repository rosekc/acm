//2017-07-29-20.42
//1003

#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;


const int maxn = 250000 + 10, mod = 1e9 + 7;
const int maxj = log2(maxn) + 1;
int b[maxn], d[maxn][maxj], n;
int init() {
    for (int i = 1; i <= n; i++) {
        cin >> d[i][0];
        d[i][0] -= i;
    }
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 1; i + j - 1 <= n; i++) {
            if (j >= maxj || i + (1 << (j - 1)) >= maxn) {
                //cout << "fuck";
                continue;
            }
            d[i][j] = max(d[i][j - 1], d[i + (1 << (j - 1))][j - 1]);
        }
    }
}
int query(int L, int R) {
    int k = 0;
    while ((1 << (k + 1)) <= R - L + 1) k++;
    if (k >= maxj || R - (1 << k) + 1 >= maxn) {
        //cout << "fuck";
        return 1;
    }
    return max(d[L][k], d[R - (1 << k) + 1][k]);
}

int main() {
    ios::sync_with_stdio(false);
    while (cin >> n) {
        init();
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        sort(b, b + n);
        int ans = 0;
        int maxb = -1;
        for (int i = 0; i < n; i++) {
            int nval = max(query(b[i], n), maxb);
            ans = (ans + nval) % mod;
            maxb = max(maxb, nval - n - i - 1);
        }
        cout << ans << endl;
    }
}
