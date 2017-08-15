//2017-08-12-13.55
//1006

#include <bits/stdc++.h>

using namespace std;

string s[110];
int vis[110][110];
int mr[] = { -1, 0, 1, 0};
int mc[] = {0, 1, 0, -1};
int n, m;
bool dfs(int i, int j, int co) {
    if (vis[i][j]) return 0;
    vis[i][j] = co;
    for (int p = 0; p < 4; p++) {
        int nx = i + mr[p];
        int ny = j + mc[p];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && s[nx][ny] == s[i][j]) {
            dfs(nx, ny, co);
        }
    }
    return 1;
}

int f[110];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> n >> m) {
        memset(vis, 0, sizeof vis);
        int co = 1;
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }
        int ind = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dfs(i, j, co)) {
                    if (s[i][j] == '1') {
                        if (ind == -1) ind = co;
                        else {
                            cout << -1 << endl;
                            goto ex;
                        }
                    }
                    co++;
                }
            }
        }
        //        for (int i = 0; i < n; i++) {
        //            for (int j = 0; j < m; j++) {
        //                cout << vis[i][j];
        //            }
        //            cout << endl;
        //        }
        if (ind == -1) {
            cout << -1 << endl;
            goto ex;
        }
        for (int i = 0; i < n; i++) {
            f[i] = 0;
            for (int j = 0; j < m; j++) {
                if (vis[i][j] == ind) {
                    while (j < m && vis[i][j] == ind) {
                        j++;
                    }
                    f[i]++;
                }
            }
            if (f[i] >= 3) {
                cout << -1 << endl;
                goto ex;
            }
        }
        for (int i = 0; i < n; i++) {
            if (f[i] == 1) {
                while (i < n && f[i] == 1) i++;
                while (i < n && f[i] == 0) i++;
                if (i == n) {
                    cout << 1 << endl;
                    goto ex;
                }
                while (i < n && f[i] == 2) i++;
                while (i < n && f[i] == 1) i++;
                while (i < n && f[i] == 0) i++;
                if (i == n) {
                    cout << 0 << endl;
                    goto ex;
                } else {
                    cout << -1 << endl;
                    goto ex;
                }
            }
        }
        cout << -1 << endl;
ex:
        int a233;
    }
}
