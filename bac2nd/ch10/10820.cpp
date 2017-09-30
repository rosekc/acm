//2017-09-02-23.38
//Uva 10820

#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e4 + 100;
int phi[maxn];
int ans[maxn];
int main() {
    phi[1] = 1;
    for (int i = 2; i < maxn; i++) {
        if (!phi[i]) {
            for (int j = i; j < maxn; j += i) {
                if (!phi[j]) phi[j] = j;
                phi[j] = phi[j] / i * (i - 1);
            }
        }
    }
    ans[1] = 1;
    for (int i = 2; i < maxn; i++) {
        //cout << phi[i] << endl;
        ans[i] = ans[i - 1] + 2 * phi[i];
    }
    int n;
    while (cin >> n && n) {
        cout << ans[n] << endl;
    }
}
