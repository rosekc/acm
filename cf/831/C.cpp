//2017-07-13-23.40
//C

#include <bits/stdc++.h>

using namespace std;

struct St {
    int cnt, lastvis;
};
unordered_map<int, St> m;
int a[2010], b[2020], sum[2020];

int main() {
    int n, k;
    cin >> k >> n;
    for (int i = 1; i <= k; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            auto it = m.find(b[i] - sum[j]);
            if (it == m.end()) {
                m[b[i] - sum[j]] = {1, i};
                continue;
            }
            if (it->second.lastvis != i) {
                it->second.lastvis = i;
                it->second.cnt++;
            }
        }
    }
    int cnt = 0;
    for (auto i : m) {
        if (i.second.cnt == n) cnt++;
    }
    cout << cnt << endl;
}
