//2017-07-27-00.04
//Uva 10305

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e3;
bool g[maxn][maxn], vis[maxn];
int indge[maxn];

int main() {
    int n, m;
    while (cin >> n >> m && n) {
        memset(g, 0, sizeof g);
        memset(indge, 0, sizeof indge);
        memset(vis, 0, sizeof vis);
        int a, b;
        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            if (!g[a][b]) {
                indge[b]++;
                g[a][b] = 1;
            }
        }
        queue<int> que;
        for (int i = 1; i <= n; i++) {
            if (indge[i] == 0) que.push(i);
        }
        bool first = 1;
        while (!que.empty()) {
            int cur = que.front();
            if (vis[cur]) {
                cout << "Error.." << endl;
                continue;
            }
            vis[cur] = 1;
            if (first) cout << cur;
            else cout << " " << cur;
            first = 0;
            que.pop();
            for (int i = 1; i <= n; i++) {
                if (g[cur][i] && --indge[i] == 0) {
                    que.push(i);
                }
            }
        }
        cout << endl;
    }
}
