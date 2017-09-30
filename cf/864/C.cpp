//2017-09-25-19.03
//C

#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, f, k;
    cin >> a >> b >> f >> k;
    int p = 2 * f, q = 2 * (a - f);
    int c = b - f;
    int ans = 0;
    if (c < 0) {
        puts("-1");
        return 0;
    }
    for (int i = 1; i < k; i++) {
        int j = (i % 2) ? q : p;
        if (c >= j) {
            c -= j;
        } else {
            c = b - j;
            ans++;
            if (c < 0) {
                puts("-1");
                return 0;
            }
        }
    }
    int j = (k % 2) ? q / 2 : p / 2;
    if (c >= j) {
        c -= j;
    } else {
        c = b - j;
        ans++;
        if (c < 0) {
            puts("-1");
            return 0;
        }
    }
    cout << ans << endl;
}
