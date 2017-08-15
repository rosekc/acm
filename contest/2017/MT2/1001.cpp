//2017-07-27-12.17
//1001

#include <bits/stdc++.h>
using namespace std;

int n, x, y;
string s1, s2;

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> x >> y;
        cin >> s1 >> s2;
        int cnt1 = 0;
        for (int i = 0; i < n; i++) {
            if (s1[i] == s2[i]) cnt1++;
        }
        int cnt2 = n - cnt1;
        int same = min(x, y);
        x -= min(cnt1, same);
        y -= min(cnt1, same);
        if (x + y <= cnt2) {
            puts("Not lying");
            continue;
        }
        puts("Lying");
    }
}
