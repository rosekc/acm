//2017-07-31-15.37
//C

#include <bits/stdc++.h>

using namespace std;
const int maxx = 1e6 + 100;

long long getx(long long a, long long b) {
    long long val = a * b;
    long long l = 0, r = maxx;
    long long m;
    while (l < r) {
        //cout << m << endl;
        m = (l + r) / 2;
        long long cur = m * m * m;
        if (cur == val) return m;
        if (cur < val) {
            l = m + 1;
        }else {
            r = m;
        }
    }
    return m;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    long long a, b;
    cin >> T;
    while (T--) {
        cin >> a >> b;
        long long x = getx(a, b);
        //cout << x << endl;
        if (x * x * x == a * b && a % x == 0 && b % x == 0) {
            cout << "Yes\n";
        }else cout << "No\n";
    }
}
