//2017-07-12-10.48
//Uva 1347

#include <bits/stdc++.h>

using namespace std;

struct Point {
    int x, y;
};

double cald(Point a, Point b) {
    return sqrt(abs(a.x - b.x) * abs(a.x - b.x)
        + abs(a.y - b.y) * abs(a.y - b.y));
}

const int maxn = 1010;
int n;
double d[maxn][maxn];
bool vis[maxn][maxn];
Point a[maxn];

double dp(int i, int j) {
    //cout << i << " " << j << endl;
    if (vis[i][j]) return d[i][j];
    vis[i][j] = 1;
    //if (i == n) return cald(a[j], a[n]);
    double &ans = d[i][j] = dp(i + 1, j) + cald(a[i], a[i + 1]);
    ans = min(ans, dp(i + 1, i) + cald(a[j], a[i + 1]));
    return ans;
}

int main() {
    while (cin >> n) {
        memset(vis, 0, sizeof vis);
        for (int i = 1; i <= n; i++) {
            cin >> a[i].x >> a[i].y;
        }
        for (int i = 1; i < n - 1; i++) {
            vis[n - 1][i] = 1;
            d[n - 1][i] = cald(a[n - 1], a[n]) + cald(a[i], a[n]);
        }
        printf("%.2f\n", dp(1, 1));
    }
}
