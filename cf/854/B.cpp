//2017-09-06-21.14
//B

#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;
    if (n == k || k == 0) {
        cout << 0 << " " << 0 << endl;
        return 0;
    }
    cout << 1 << " ";

    if (k * 3 <= n){
        cout << 2 * k << endl;
    }else {
        cout << n - k << endl;
    }
}
