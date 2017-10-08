//2017-10-06-21.58
//B

#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9;

int main() {
    long long a, b;
    cin >> a >> b;
    long long t = 1;
    for (long long i = a + 1; i <= b; i++) {
        t *= (i % mod);
        t %= mod;
        if (t % 10 == 0) {
            puts("0");
            return 0;
        }
    }
    cout << t % 10 << endl;
}
