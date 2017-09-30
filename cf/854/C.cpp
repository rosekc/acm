//2017-09-06-21.41
//C

#include <bits/stdc++.h>

using namespace std;

const int maxn = 300000 + 100;
int a[maxn];
int re[maxn];
priority_queue<pair<int, int>, vector<pair<int, int> >, less<pair<int, int> > > q;


int main() {
    int n, k;
    long long t = 0, ans = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (i <= k) {
            q.push({a[i], i});
            t += a[i];
            ans += 1ll * a[i] * (k - i + 1);
        }
    }
    int p = k + 1;
    while (!q.empty()) {
        if (p <= n) {
            q.push({a[p], p});
            t += a[p];
        }
        auto c = q.top();
        q.pop();
        //cout << c.second << endl;
        re[c.second] = p;
        t -= c.first;
        ans += t;
        p++;
    }
    cout << ans << endl;
    for (int i = 1; i <= n; i++) {
        cout << re[i] << " ";
    }
    cout << endl;
}
