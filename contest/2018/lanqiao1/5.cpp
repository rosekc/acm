#include <bits/stdc++.h>

using namespace std;

int d[9][9];

bool dfs(int x, int y) {
    // for (int i = 0; i < 9; i++) {
    //     for (int j = 0; j < 9; j++) {
    //         cout << d[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    if (x == 9) {
        return 1;
    }
    if (d[x][y] == 0) {
        for (int i = 1; i <= 9; i++) {
            bool ok = 1;
            for (int j = 0; j < 9; j++) {
                if (d[j][y] == i || d[x][j] == i) {
                    ok = 0;
                    goto ed;
                }
            }
            for (int j = x / 3 * 3; j < x / 3 * 3 + 3; j++) {
                for (int k = y / 3 * 3; k < y / 3 * 3 + 3; k++) {
                    //cout << j << " " << k << endl;
                    if (d[j][k] == i) {
                        ok = 0;
                        goto ed;
                    }
                }
            }
        ed:
            if (ok) {
                d[x][y] = i;
                if (y + 1 == 9 && dfs(x + 1, 0)) {
                    return 1;
                } else if (dfs(x, y + 1))
                    return 1;
                d[x][y] = 0;
            }
        }
    } else {
        if (y + 1 == 9 && dfs(x + 1, 0)) {
            return 1;
        } else if (dfs(x, y + 1))
            return 1;
    }
    return 0;
}

int main() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> d[i][j];
        }
    }
    dfs(0, 0);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << d[i][j] << " ";
        }
        cout << endl;
    }
}