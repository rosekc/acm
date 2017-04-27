//2017-04-27-13.32
//Uva 1347

#include <bits/stdc++.h>

using namespace std;

struct Point {
    int x, y;
    Point operator - (const Point &b)const {
        return {x - b.x, y - b.y};
    }
    double operator *(const Point &b)const {
        return x * b.x + y * b.y;
    }
};

double dist(Point a, Point b) {
    return sqrt((a - b) * (a - b));
}

Point d[1010];
double dp[1010][1010];
bool vis[1010][1010];

double cal(int i, int j) {
    //cout << i << " " << j << endl;
    if (vis[i][j]) return dp[i][j];
    vis[i][j] = 1;
    return dp[i][j] = min(cal(i + 1, j) + dist(d[i], d[i + 1]), cal(i + 1, i) + dist(d[j], d[i + 1]));
}

int main() {
    int n;
    while (cin >> n) {
        memset(vis, 0, sizeof vis);
        for (int i = 1; i <= n; i++) {
            cin >> d[i].x >> d[i].y;
        }
        for (int i = 1; i < n - 1; i++) {
            vis[n - 1][i] = 1;
            dp[n - 1][i] = dist(d[n - 1], d[n]) + dist(d[i], d[n]);
        }
        printf("%.2f\n", cal(1, 1));
    }
}
