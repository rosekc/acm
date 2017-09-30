//2017-09-23-19.56
//E

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x, t;
    cin >> n >> x;
    int p = x;
    while (n--) {
        cin >> t;
        if (t < x) p--;
        if (t == x) p++;
    }
    cout << p << endl;
}
