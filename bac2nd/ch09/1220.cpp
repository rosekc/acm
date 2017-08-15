//2017-07-23-22.15
//Uva 1220

#include <bits/stdc++.h>

using namespace std;

int n;
string root;
unordered_map<string, vector<string> > m;

struct St {
    int ans;
    bool uniqued;
};

St d(string cur, bool chosen) {
    //cout << cur << endl;
    int ans = 0;
    auto &next = m[cur];
    bool uniqued = 1;
    if (chosen) {
        for (auto i : next) {
            St a = d(i, 0);
            if (!a.uniqued) uniqued = 0;
            ans += a.ans;
        }
        return {ans + 1, uniqued};
    }
    for (auto i : next) {
        St a = d(i, 0), b = d(i, 1);
        if (a.ans < b.ans) swap(a, b);
        if (!a.uniqued || a.ans == b.ans) uniqued = 0;
        ans += a.ans;
    }
    return {ans, uniqued};
}

int main() {
    string a, b;
    while (cin >> n && n) {
        cin >> root;
        m.clear();
        for (int i = 1; i < n; i++) {
            cin >> a >> b;
            m[b].push_back(a);
        }
        St a = d(root, 0);
        St b = d(root, 1);
        if (a.ans < b.ans) swap(a, b);
        cout << a.ans << " " << (a.uniqued && a.ans != b.ans ? "Yes" : "No") << endl;
    }
}
