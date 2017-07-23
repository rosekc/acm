//2017-07-13-10.45
//Uva 11400

#include <bits/stdc++.h>

using namespace std;

struct St {
    int v, k, c, l;
    bool operator<(const St &b)const {
        return v < b.v;
    }
};

int n;
St a[1010];
int d[1010], sum[1010];

int main() {
    while (cin >> n && n) {
        for (int i = 1; i <= n; i++) {
            cin >> a[i].v >> a[i].k >> a[i].c >> a[i].l;
        }
        sort(a + 1, a + 1 + n);
        for (int i = 1; i <= n; i++) {
            sum[i] = sum[i - 1] + a[i].l;
        }
        d[1] = a[1].k + a[1].c * a[1].l;
        for (int i = 2; i <= n; i++) {
            d[i] = d[i - 1] + a[i].l * a[i].c + a[i].k;
            for (int j = 0; j < i; j++) {
                d[i] = min(d[i], d[j] + (sum[i] - sum[j]) * a[i].c + a[i].k);
            }
        }
        cout << d[n] << endl;
    }
}
