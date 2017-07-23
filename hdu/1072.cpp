//2017-07-17-00.05
//Nigthmare

#include <bits/stdc++.h>

using namespace std;

int mr[] = {1, 0, -1, 0};
int mc[] = {0, 1, 0, -1};
int g[10][10];
int vis[10][10];
struct St {
    int x, y, t, p;
};

int main() {
    int T, n, m;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        queue<St> que;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> g[i][j];
                vis[i][j] = 0;
                if (g[i][j] == 2) {
                    que.push({i, j, 6, 0});
                    vis[i][j] = 6;
                }
            }
        }
        int ans = -1;
        while (!que.empty()) {
            St cur = que.front();
            que.pop();
            for (int i = 0; i < 4; i++) {
                int nx = cur.x + mr[i];
                int ny = cur.y + mc[i];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                        g[nx][ny] != 0) {
                    //cout << nx << " " << ny << endl;
                    St next_st = {nx, ny, cur.t - 1, cur.p + 1};
                    if (cur.t == 0 || next_st.t <= vis[nx][ny]) continue;
                    if (g[nx][ny] == 3) {
                        ans = next_st.p;
                        break;
                    }
                    if (g[nx][ny] == 4) next_st.t = 6;
                    vis[nx][ny] = next_st.t;
                    que.push(next_st);
                }
            }
            if (ans != -1) break;
        }
        cout << ans << endl;
    }
}
