//2017-10-31-09.03
//K

#include <bits/stdc++.h>
using namespace std;

const int maxn = 300 + 10;
bool used[maxn];
int linker[maxn];
int n, s;
bool dfs(int u) {
    for (int v = s + 1; v <= s + n; v++) {
        //cout << v << " " << u << endl;
        if (v % u == 0 && !used[v - s]) {
            used[v - s] = true;
            if (linker[v - s] == -1 || dfs(linker[v - s])) {
                linker[v - s] = u;
                return true;
            }
        }
    }
    return false;
}
int hungary() {
    int res = 0;
    memset(linker, -1, sizeof(linker));
    for (int u = 1; u <= n; u++) { //µãµÄ±àºÅ0~uN-1
        memset(used, false, sizeof(used));
        if (dfs(u))res++;
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, kase = 1;
    cin >> T;
    while (T--) {
        cin >> n >> s;
        if (n > s) swap(n, s);
        //cout << hungary() << endl;
        if (n < 300 && hungary() == n) {
            cout << "Case #" << kase++ << ": Yes" << endl;
        }else {
            cout << "Case #" << kase++ << ": No" << endl;
        }
    }
}
