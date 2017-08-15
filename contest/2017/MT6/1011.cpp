//2017-08-10-12.47
//1011

#include <bits/stdc++.h>

using namespace std;

int main() {
    int T, n, a, b, c, d, e, f, g;
    cin >> T;
    while (T--) {
        int ans = -1;
        cin >> n;
        while (n--) {
            cin >> a >> b >> c >> d >> e >> f >> g;
            int aa = a + g - d - f;
            int bb = b + g - d - e;
            int cc = c + g - e - f;
            if (min(a, b) < d || min(a, c) < f || min(b, c) < e || min(d, min(e, f)) < g || aa < 0 || bb < 0 || cc < 0)
                continue;
            int t = a + b + c - d - e - f + g;
            //cout << t << endl;
            if (t < 0) continue;
            ans = max(ans, t);
        }
        cout << ans << endl;
    }
}
