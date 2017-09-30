#include <bits/stdc++.h>
using namespace std;

const int dx[4] = { -1, 1, 1, -1 };
const int dy[4] = { -1, -1, 1, 1 };

const int N = 100;

int flag[N][N];
int n, m;

void dfs(int x, int y, int fx) {
    flag[x][y]++;
    if (!(x == n && y == 1) && ((x == n && y == m) || (x == 1 && y == 1) || (x == 1 && y == m)))
        return;
    int tfx = fx;
    if (!(x == n && y == 1)) {
        if (x == n) {
            if (fx == 1)
                tfx = 0;
            else if (fx == 2)
                tfx = 3;
        } else if (x == 1) {
            if (fx == 3)
                tfx = 2;
            else if (fx == 0)
                tfx = 1;
        } else if (y == 1) {
            if (fx == 1)
                tfx = 2;
            else if (fx == 0)
                tfx = 3;
        } else if (y == m) {
            if (fx == 2)
                tfx = 1;
            else if (fx == 3)
                tfx = 0;
        }
    }
    dfs(x + dx[tfx], y + dy[tfx], tfx);
}

int s() {

    memset(flag, 0, sizeof flag);
    dfs(n, 1, 3);
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (flag[i][j] == 1)
                cnt++;
            //printf("%d ", flag[i][j]);
            //if (j == m) puts("");
        }
    return cnt;
    //        printf("n=%d m=%d:", n, m);
    //        printf("%d\n", cnt);
}

int main() {
    for (int i = 2; i <= 30; i++) {
        for (int j = 2; j <= 20; j++) {
            n = i, m = j;
            cout << setw(3) << s() << " ";
        }
        cout << endl;
    }
    return 0;
}
