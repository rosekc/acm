//2017-07-25-16.40
//1011

#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, k;
    int kase = 1;
    while (cin >> n >> k) {
        printf("Case #%d: ", kase++);
        if (n == 1) {
            cout << 1 << endl;
            continue;
        }
        if (k <= n) {
            cout << k << endl;
            continue;
        }
        k -= n;
        if (k % (n - 1) != 0) cout << k % (n - 1) << endl;
        else cout << ((k / (n - 1) % 2) ? n - 1 : n) << endl;
    }
}
