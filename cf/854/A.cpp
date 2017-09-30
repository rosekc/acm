//2017-09-06-20.57
//A

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e3 + 100;

int main() {
    int n;
    cin >> n;
    for (int i = 1000; i >= 0; i--) {
        for (int j = 0; j <= 1000; j++) {
            if (i < j && i + j == n && __gcd(i, j) == 1) {
                cout << i << " " << j << endl;
                return 0;
            }
        }
    }
}
