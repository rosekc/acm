//2017-07-13-23.01
//A

#include <bits/stdc++.h>

using namespace std;

int a[105];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << "Yes" << endl;
        return 0;
    }
    bool f1, f2, f3;
    f1 = f2 = f3 = 0;
    int i = 1;
    while (a[i] > a[i - 1] && i < n) {
        f1 = 1;
        i++;
    }
    while (a[i] == a[i - 1] && i < n) {
        f2 = 1;
        i++;
    }
    while (a[i] < a[i - 1] && i < n) {
        f3 = 1;
        i++;
    }
    if (i == n && (f1 || f3 || f2)) puts("YES");
    else puts("NO");
}
