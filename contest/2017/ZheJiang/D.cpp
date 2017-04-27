//2017-04-22-14.58
//D

#include <bits/stdc++.h>

using namespace std;

int dx[105][2], dy[105][2];
int T, n, m, x, y;

int check(int i, int j) {
    //printf("%d %d\n", i, j);
    if (dx[i][1] >= dy[j][0] || dx[i][0] <= dy[j][1]) {
        return min(min(dx[i][1], dy[j][1]), n) - max(dx[i][0], dy[j][0]);
    }
    return -1;
}

int main() {
    cin >> T;
    while (T--) {
        cin >> n >> m >> x >> y;
        for (int i = 0; i < x; i++) {
            cin >> dx[i][0] >> dx[i][1];
        }
        for (int i = 0; i < y; i++) {
            cin >> dy[i][0] >> dy[i][1];
        }
        int ix = 0, iy = 0, re = 0;
        while (1) {
            int ans = check(ix, iy);
            //cout << "  " << ans << "\n";
            if (ans >= 0) {
                if (ans + 2 - m > 0) re += (ans + 2 - m);
                //printf("re:%d\n", re);
            }
            if (dx[ix][1] > dy[iy][1]) iy++;
            else if (dx[ix][1] < dy[iy][1]) ix++;
            else {
                ix++;
                iy++;
            }
            if (ix >= x || iy >= y || dx[ix][0] > n || dy[iy][0] > n) break;
        }
        cout << re << endl;
    }
}
