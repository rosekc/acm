//2017-07-23-17.41
//Uva 12186

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;
vector<int> g[maxn];
int n, t;

int dp(int cur) {
    int vsize = g[cur].size();
    if (vsize == 0) return 1;
    vector<int> d;
    for (int i = 0; i < vsize; i++) {
        d.push_back(dp(g[cur][i]));
    }
    sort(d.begin(), d.end());
    int cnt = (t * vsize - 1) / 100 + 1, ans = 0;
    for (int i = 0; i < cnt; i++) ans += d[i];
    return ans;
}

int main() {
    int tmp;
    while (cin >> n >> t && n) {
        for (int i = 0; i <= n; i++) g[i].clear();
        for (int i = 1; i <= n; i++) {
            cin >> tmp;
            g[tmp].push_back(i);
        }
        cout << dp(0) << endl;
    }
}
