//2017-08-29-23.25
//B

#include <bits/stdc++.h>
using namespace std;

double dist(int x, int y) {
    return sqrt(x * x + y * y);
}

int sgn(double x) {
    if (fabs(x) < 1e-9)return 0;
    if (x < 0)return -1;
    else return 1;
}

int main() {
    int r, d, n;
    int cnt = 0;
    cin >> r >> d >> n;
    while (n--)  {
        int x, y, ri;
        cin >> x >> y >> ri;
        double dis = dist(x, y);
        if (dis + ri <= r && dis - ri >= r - d)  {
            cnt++;
        }
    }
    cout << cnt << endl;
}
