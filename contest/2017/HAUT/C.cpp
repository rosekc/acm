//2017-04-23-13.37
//C

#include <bits/stdc++.h>

using namespace std;

int d[100100];
vector<pair<int, int> > g[100100];
vector<int> nextp[100100];

queue<int> qu;
set<int> vis;

int main() {
    int T, n, m;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        vis.clear();
        for (int i = 1; i <= n; i++) {
            cin >> d[i];
            g[i].clear();
            nextp[i].clear();
        }
        for (int i = 0; i < m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            g[c].push_back({a, b});
            nextp[a].push_back(c);
            nextp[b].push_back(c);
            qu.push(c);
            vis.insert(c);
        }
        while (!qu.empty()) {
            int cur = qu.front();
            qu.pop();
            vis.erase(cur);
            for (auto pii : g[cur]) {
                if (d[cur] > d[pii.first] + d[pii.second]) {
                    d[cur] = d[pii.first] + d[pii.second];
                    for (int i : nextp[cur]) {
                        if (!vis.count(i)) {
                            vis.insert(i);
                            qu.push(i);
                        }
                    }
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            cout << d[i];
            if (i != n) putchar(' ');
        }
        puts("");
    }
}
