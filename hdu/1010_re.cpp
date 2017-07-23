//2017-07-17-00.43
//Tempter of the Bone

#include <bits/stdc++.h>

using namespace std;

int mr[] = {1, 0, -1, 0};
int mc[] = {0, 1, 0, -1};
char g[20][20];
bool vis[20][20];
int si, sj, ei, ej;
int n, m, t;

bool dfs(int x, int y, int p) {
    vis[x][y] = 1;
    if (p == t) {
        if (g[x][y] == 'D') return 1;
        vis[x][y] = 0;
        return 0;
    }
    if (g[x][y] == 'D') {
        vis[x][y] = 0;
        return 0;
    }
    for (int i = 0; i < 4; i++) {
        int nx = x + mr[i];
        int ny = y + mc[i];

        if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                g[nx][ny] != 'X' && !vis[nx][ny]) {
            //cout << nx << " " << ny << endl;
            if (dfs(nx, ny, p + 1)) return 1;
        }
    }
    vis[x][y] = 0;
    return 0;
}

int dist(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

char readchar() {
    char c = getchar();
    while (c == '\n' || c == ' ' || c == '\c') c = getchar();
}

int main() {
    while (cin >> n >> m >> t && n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> g[i][j];
                vis[i][j] = 0;
                if (g[i][j] == 'S') {
                    si = i;
                    sj = j;
                } else if (g[i][j] == 'D') {
                    ei = i;
                    ej = j;
                }
            }
        }
        if (dist(si, sj, ei, ej) <= t && (t - dist(si, sj, ei, ej)) % 2 == 0
            && dfs(si, sj, 0)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
