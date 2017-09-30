//2017-09-04-22.37
//A

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k, t;
    cin >> n >> k >> t;
    if (t <= k) {
        cout << t << endl;
        return 0;
    }
    if (t >= n) {
        cout <<  k - (t - n) << endl;
        return 0;
    }
    cout << k << endl;
}
