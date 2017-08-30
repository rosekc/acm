//2017-08-27-21.31
//Uva 12716

#include <bits/stdc++.h>
using namespace std;

const int maxn = 30000000 + 10;

int ans[maxn], cnt[maxn];

void cal() {
    for (int c = 1; c < maxn; c++) {
        for (int a = c; a < maxn; a += c) {
            int b = a ^ c;
            if (b >= 1 && b <= a && a == b + c) cnt[a]++;
        }
    }
    for (int i = 1; i < maxn; i++) {
        ans[i] = ans[i - 1] + cnt[i];
    }
}

int main() {
    cal();
    int T, kase = 1, n;
    cin >> T;
    while (T--) {
        cin >> n;
        printf("Case %d: %d\n", kase++, ans[n]);
    }
}
