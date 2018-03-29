//2017-10-27-22.29
//Uva 11235

#include <bits/stdc++.h>

using namespace std;

const int maxn = 200000 + 100;
const int maxj = log2(maxn) + 1;
int a[maxn], d[maxn][maxj];
int init(vector<int> &v) {
    int n = v.size();
    for (int i = 0; i < n; i++) {
        d[i][0] = v[i];
    }
    for (int j = 1; (1<<j) <= n; j++) {
        for (int i = 0; i + (1<<j) - 1 < n; i++) {
            d[i][j] = max(d[i][j - 1], d[i + (1<<(j - 1))][j - 1]);
        }
    }
}
int query(int L, int R) {
    int k = 0;
    while ((1<<(k + 1)) <= R - L + 1) k++;
    return max(d[L][k], d[R - (1<<k) + 1][k]);
}
int num[maxn], le[maxn], ri[maxn];


int main() {
    int q, l, r, n;
    while (cin >> n && n) {
        cin >> q;
        for (int i = 0; i < n; i++) cin >> a[i];
        a[n] = maxn + 1;
        vector<int> v;
        int st = -1;
        for (int i = 0; i <= n; i++) {
            if (i == 0 || a[i] > a[i - 1]) {
                if (i > 0) {
                    v.push_back(i - st);
                    for (int j = st; j < i; j++) {
                        le[j] = st;
                        ri[j] = i;
                        num[j] = v.size() - 1;
                    }
                }
                st = i;
            }
        }
//        for (int i : v) {
//            cout << i << endl;
//        }
        init(v);
        while (q--) {
            cin >> l >> r;
            l--; r--;
            int lc = num[l], rc = num[r];
            if (lc == rc) {
                cout << r - l + 1 << endl;
                continue;
            }
            int ans = max(ri[l] - l, r + 1 - le[r]);
            if (rc > lc + 1) {
                ans = max(query(lc + 1, rc - 1), ans);
            }
            cout << ans << endl;
        }
    }
}
