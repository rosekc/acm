//2017-09-04-00.29
//Uva 11462

#include <bits/stdc++.h>

using namespace std;

int a[101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, t;
    while (cin >> n && n) {
        while (n--) {
            cin >> t;
            a[t]++;
            //assert(a[t] >= 0);
        }
        bool first = 1;
        for (int i = 1; i <= 100; i++) {
            //assert(a[i] >= 0);
            while (a[i]) {
                if (!first) {
                    cout << " ";
                }
                cout << i;
                first = 0;
                a[i]--;
            }
            //assert(a[i] >= 0);
        }
        cout << '\n';
    }
}
