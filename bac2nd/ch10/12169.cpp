//2017-08-27-00.10
//Uva 12169

#include <bits/stdc++.h>
using namespace std;

const int m = 10001;
int x[2 * m];

int main() {
    int n;
    while (cin >> n) {
        for (int i = 1, t = 0; t < n; t++, i += 2) {
            cin >> x[i];
        }
        bool ok;
        for (int a = 0; a <= m; a++) {
            for (int b = 0; b <= m; b++) {
                ok = 1;
                for (int i = 1, t = 0; t < n - 1; t++, i += 2) {
                    int p = (x[i] * a + b) % m;
                    if (x[i + 2] == (p * a + b) % m) {
                        x[i + 1] = p;
                    } else {
                        ok = 0;
                        break;
                    }
                }
                if (ok) {
                    x[2 * n] = (x[2 * n - 1] * a + b) % m;
                    break;
                }
            }
            if (ok) break;
        }
        for (int i = 2, t = 0; t < n; t++, i += 2) {
            cout << x[i] << endl;
        }
    }
}
