//2017-07-29-14.50
//1011

#include <bits/stdc++.h>

using namespace std;

const int maxn = 300;
bool g[maxn][maxn];

bool& get(int x, int y) {
    bool& rtn = g[x + 100][y + 100];
    return rtn;
}

bool check(int i, int j, int x, int y) {
    bool ans = 1;
    if (i - x < 0 || j + y > 200) return 0;
    i -= x; j += y;
    if (!g[i][j]) return 0;
    if (i + y > 200 || j + x > 200) return 0;
    i += y; j += x;
    if (!g[i][j]) return 0;
    if (i + x > 200) return 0;
    i += x; j -= y;
    if (!g[i][j]) return 0;
    return 1;
}

int main() {
    ios::sync_with_stdio(false);
    int n, a, b;
    while (cin >> n) {
        memset(g, 0, sizeof g);
        while (n--) {
            cin >> a >> b;
            get(a, b) = 1;
        }
        int cnt = 0;
        for (int i = 0; i <= 200; i++) {
            for (int j = 0; j <= 200; j++) {
                if (g[i][j]) {
                    for (int x = 1; i - x >= 0; x++) {
                        for (int y = 0; j + y <= 200; y++) {
                            if (check(i, j, x, y)) cnt++;
                        }
                    }
                }
            }
        }
        cout << cnt << endl;
    }
}
