//2017-08-29-22.59
//A

#include <bits/stdc++.h>
using namespace std;

int main() {
    long long l, r, x, y, k;
    cin >> l >> r >> x >> y >> k;
    for (int i = x; i <= y; i++) {
        if (i * k >= l && i * k <= r) {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
}

