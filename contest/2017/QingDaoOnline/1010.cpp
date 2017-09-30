//2017-09-17-12.06
//1010

#include <bits/stdc++.h>

using namespace std;

int a[100000 + 10];
int gg[100000 + 10];

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            int l, r;
            l = r = i;
            while (l >= 0 && !gg[l] && a[l] > a[r]) {
                gg[l] = 1;
                l--;
            }
            while (r < n && !gg[r] && a[l] > a[r]) {
                gg[r] = 1;
                r++;
            }
        }
    }
}
