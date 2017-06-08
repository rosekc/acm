//2017-06-07-20.38
//B

#include <bits/stdc++.h>

using namespace std;
int n, a[1005], b[1005], ans[1005];
int vis[1005];
vector<int> vpos;
bool dfs(int i) {
    //    cout << i << endl;
    if (i == vpos.size()) return 1;
    //    cout << a[vpos[i]] << endl;
    if (!vis[a[vpos[i]]]) {
        vis[a[vpos[i]]] = 2;
        ans[vpos[i]] = a[vpos[i]];
        if (dfs(i + 1)) return true;
        vis[a[vpos[i]]] = 0;
    }
    //    puts("123");
    if (!vis[b[vpos[i]]]) {
        vis[b[vpos[i]]] = 2;
        ans[vpos[i]] = b[vpos[i]];
        if (dfs(i + 1)) return true;
        vis[b[vpos[i]]] = 0;
    }
    return false;
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) {
        if (a[i] == b[i]) vis[a[i]] = 1;
        else vpos.push_back(i);
    }
    if (!dfs(0)) {
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {ans[vpos[0]] = i; break;}
        }
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] == b[i]) cout << a[i] << " ";
        else cout << ans[i] << " ";
    }
    cout << endl;
}
