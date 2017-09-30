//2017-09-23-19.51
//D

#include <bits/stdc++.h>

using namespace std;

int a[1010];

int main() {
    int n, t;
    cin >> n;
    while (n--) {
        cin >> t;
        a[t]++;
    }
    for (int i = 3; i <= 1000; i++) {
        if (a[i - 2] && a[i - 1] && a[i]) {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
}
