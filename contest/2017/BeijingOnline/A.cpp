//2017-09-23-12.16
//A

#include <bits/stdc++.h>

using namespace std;

const int maxn = 105;
int a[maxn];
bool gg[maxn];
struct ans {
    int a, b, p;
};
int main() {
    int n, m, q, t;
    while (cin >> n >> m) {
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            gg[i] = 0;
        }
        cin >> q;
        for (int i = 0; i < q; i++) {
            cin >> t;
            gg[t] = 1;
        }
        int p = 0;
        int l = 0;
        ans re = {-1, -1, 9999999};
        while (l < n && gg[l]) l++;
        for (int i = l; i < n; i++) {
            while (i < n && gg[i]) i++;
            if (i >= n) break;
            p++;
            //cout << p << endl;
            //cout << l << " " << i << endl;
            if (p == m) {
                int minp = 999999, ind = -1;
                for (int j = l + 1; j <= i; j++){
                    if (!gg[j] && minp > a[j]) {
                        minp = a[j];
                        ind = j;
                    }
                }
                int aa = l;
                int t = a[l];
                int b = ind;
                t += minp;
                //cout << aa << " " << b << " " << t << endl;
                if (re.p > t) {
                    re = {aa, b, t};
                }
                p--;
                l++;
                while (l != i && gg[l]) l++;
            }
        }
        //assert(re.a != -1);
        cout << re.a << " " << re.b << endl;
    }
}
