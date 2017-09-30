//2017-09-23-19.32
//A

#include <bits/stdc++.h>

using namespace std;

int main() {
    long long a, b;
    cin >> a >> b;
    long long c = 1;
    while (b--) {
        c *= 10;
    }
    //cout << c << " " << __gcd(a, c) << endl;
    cout << a * c / __gcd(a, c) << endl;
}
