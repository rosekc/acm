//2017-08-21-21.34
//1003

#include <bits/stdc++.h>
using namespace std;

const int maxn = 3000 + 10;

int n;
bool g[maxn][maxn], vis[maxn];

bool dfs(int c, int fa, bool f) {
    //cout << c << endl;
    vis[c] = 1;
    for (int i = 1; i <= n; i++) {
        if (i == c || g[c][i] != f) continue;
        //cout << c << ' ' << i << endl;
        if (i != fa && c != fa && g[i][fa] == f) return 1;
        if (!vis[i] && dfs(i, c, f)) {
            //vis[c] = 0;
            return 1;
        }
        //puts("gg");
    }
    //vis[c] = 0;
    return 0;
}

int main() {
    int T, t;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                cin >> t;
                g[i][j] = g[j][i] = t;
            }
        }
        bool g = 1;
        for (int f = 0; f <= 1; f++) {
            memset(vis, 0, sizeof vis);
            for (int i = 1; i <= n; i++) {
                if (!vis[i] && dfs(i, i, bool(f))) {
                    //cout << i << endl;
                    g = 0;
                    break;
                }
            }
            if (!g) break;
        }
        if (g) puts("Great Team!");
        else puts("Bad Team!");
    }
}
