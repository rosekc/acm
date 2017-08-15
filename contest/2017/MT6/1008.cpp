//2017-08-10-14.47
//1008

#include <bits/stdc++.h>

using namespace std;

int m;
string s;
int len, ans;

void solve(int i, int j) {
    int t = 0;
    queue<int> q;
    while (i >= 0 && j < len) {
        int k = abs(s[i--] - s[j++]);
        q.push(k);
        t += k;
        while (t > m && q.size() > 0) {
            t -= q.front();
            q.pop();
        }
        if (t <= m) ans = max(ans, (int) q.size());
        //cout << i << ' ' << j << ' ' << t << ' ' << q.size() << endl;
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> m >> s;
        len = s.length();
        ans = 0;
        for (int i = 0; i < len; i++) {
            solve(i, i + 1);
            solve(i - 1, i + 1);
        }
        cout << ans << endl;
    }
}
