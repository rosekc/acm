//2017-08-17-12.00
//1001

#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
vector<int> G[maxn];
bool vis[maxn];
int a[maxn], ans[maxn];
int n, T;

long long dfs(int cur, vector<int> &inv) {
    vis[cur] = 1;
    vector<int> v;
    v.push_back(a[cur]);
    for (int i : G[cur]) {
        if (!vis[i]) {
            dfs(i, v);
        }
    }
    sort(v.begin(), v.end());
    long long cnt, t;
    cnt = t = 0;
    for (int i : v) {
        //cout << i << ' ';
        t += i;
        cnt += t;
        inv.push_back(i);
    }
    //cout << endl;
    //cout << cnt << endl;
    ans[cur] = cnt;
    vis[cur] = 0;
}

int main() {
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        vector<int> v;
        dfs(1,v);
        for (int i = 1; i <= n; i++) {
            cout << ans[i] << ' ';
        }
        cout << endl;
    }
}
