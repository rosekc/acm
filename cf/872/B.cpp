//2017-10-15-16.14
//B

#include <bits/stdc++.h>

using namespace std;

int a[100000 + 10];

int main() {
    int n, k, first, last;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (k == 2) {
        cout << max(a[0], a[n - 1]) << endl;
        return 0;
    }
    first = a[0];
    last = a[n - 1];
    sort(a, a + n);
    if (k == 1) cout << a[0] << endl;
    else cout << a[n - 1] << endl;
}
