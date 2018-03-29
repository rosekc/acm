//2017-10-15-15.51
//A

#include <bits/stdc++.h>

using namespace std;

bool a[10], b[10];

int main() {
    int n, m, t;
    cin >> n >> m;
    while (n--) {
        cin >> t;
        a[t] = 1;
    }
    while (m--) {
        cin >> t;
        b[t] = 1;
    }
    for (int i = 1;; i++) {
        int p = i;
        bool f1, f2;
        f1 = f2 = 0;
        while (p > 10) {
            int x = p % 10;
            if (a[x]) f1 = 1;
            if (b[x]) f2 = 1;
            p /= 10;
        }
        if (a[p]) f1 = 1;
        if (b[p]) f2 = 1;
        if (f1 && f2) {cout << i << endl; return 0;}
    }
}
