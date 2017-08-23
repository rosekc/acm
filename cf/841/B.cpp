//2017-08-18-23.27
//B

#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
int a[maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] % 2 == 1) cnt++;
    }
    int l = 0, r = n - 1;
    if (cnt != 0) {
        puts("First");
    }else puts("Second");
}
