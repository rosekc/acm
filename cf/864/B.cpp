//2017-09-25-18.48
//B

#include <bits/stdc++.h>

using namespace std;

bool vis[26];

int main() {
    int n;
    string s;
    cin >> n >> s;
    int ans = 0, t = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            memset(vis, 0, sizeof vis);
            ans = max(t, ans);
            t = 0;
        }else {
            if (!vis[s[i] - 'a']) {
                t++;
                vis[s[i] - 'a'] = 1;
            }
        }
    }
    ans = max(t, ans);
    cout << ans << endl;
}
