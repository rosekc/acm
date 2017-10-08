//2017-10-05-16.36
//D

#include <bits/stdc++.h>
using namespace std;

string a[11000];
unordered_map<string, int> mp;

int cal(string &s, int mk = 0) {
    for (int k = mk + 1;; k++) {
        if (k + (1 << k) - 1 > s.length()) {
            //cout << 233 << endl;
            return k - 1;
        }
        unordered_set<string> st;
        for (int i = 0; i + k - 1 < s.length(); i++) {
            st.insert(s.substr(i, k));
            //cout << s.substr(i, k) << endl;
            if (st.size() == (1 << k)) break;
            if ((1 << k) - st.size() > s.length() - i - k) return k - 1;
        }
        if (st.size() != (1 << k)) return k - 1;
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int p;
    int n, m;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mp[a[i]] = cal(a[i]);
        //cout << mp[a[i]] << endl;
    }
    p = n;
    cin >> m;
    int x, y;
    auto it = mp.begin();
    while (m--) {
        cin >> x >> y;
        a[++p] = a[x] + a[y];
        if ((it = mp.find(a[p])) != mp.end()) {
            cout << it->second << endl;
            continue;
        }
        int mk = max(mp[a[x]], mp[a[y]]);
        if (mk > 4) mp[a[p]] = mk;
        else mp[a[p]] = cal(a[p], mk);
        cout << mp[a[p]] << endl;
    }
}
