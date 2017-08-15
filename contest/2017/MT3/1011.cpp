//2017-08-01-12.07
//1011

#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    int cnt = 0, t;
    while (T--) {
        cin >> t;
        if (t <= 35) cnt++;
    }
    cout << cnt << endl;
}
