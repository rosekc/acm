//2017-07-30-22.47
//B

#include <bits/stdc++.h>

using namespace std;

string s;
int st[26], ed[26];
struct St {
    int t, f;
    bool operator<(const St &b)const & {
        if (t == b.t) {
            return f > b.f;
        }
        return t < b.t;
    }
};
vector<St> v;

int main() {
    int n, k;
    cin >> n >> k >> s;
    memset(st, -1, sizeof st);
    for (int i = 0; i < s.length(); i++) {
        ed[s[i] - 'A'] = i;
        if (st[s[i] - 'A'] == -1) st[s[i] - 'A'] = i;
    }
    //puts("313");
    for (int i = 0; i < 26; i++) {
        if (st[i] != -1) {
            v.push_back({st[i], 1});
            v.push_back({ed[i], -1});
        }
    }
    sort(v.begin(), v.end());
    //puts("2330");
    int cnt = 0, t = 0;
    for (int i = 0; i < v.size(); i++) {
        t += v[i].f;
       // cout << t << endl;
        cnt = max(cnt, t);
    }
    //cout << cnt << endl;
    if (cnt > k) puts("YES");
    else puts("NO");
}
