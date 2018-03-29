//2017-10-15-16.39
//C

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, t;
    cin >> n;
    while (n--) {
        cin >> t;
        if (t % 4 == 0) {
            cout << t / 4 << endl;
        }else if (t % 4 == 1 && t > 7){
            cout << (t - 5) / 4 << endl;
        }else if (t % 4 == 2 && t != 2) {
            cout << t / 4 << endl;
        }else if (t % 4 == 3 && t > 11) {
            cout << (t - 7) / 4 << endl;
        }else cout << -1 << endl;
    }
}
