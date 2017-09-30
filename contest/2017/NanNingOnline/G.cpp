//2017-09-24-15.31
//G

#include <bits/stdc++.h>

using namespace std;

#define double long double

double ans[15];
const double PI = acos(-1.0);

double dist(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
    int l;
    double R;
    cin >> l >> R;
    double x1 = R;
    double x2 = -x1;
    double x3 = 0;
    double y3 = tan(PI / 3) * R;
    //cout << y3 << endl;
    double y1 = 0, y2 = 0;
    double oor = R;
    for (int i = 1; i <= 10; i++) {
        double l = 0, r = y3;
        double re;
        while (l < r) {
            double m = (l + r) / 2;
            cout << m << endl;
            double d1 = dist(x1, y1, 0, m);
            double d2 = abs(y3 - m);
            cout << d1 - R <<" " << d2 - oor << endl;
            if (abs(d1 - R - d2 + oor) < 1e9) {
                re = m;
                break;
            }
            if (d1 - R > d2 - oor) {
                r = m;
            } else if (d1 - R < d2 - oor) {
                l = m;
            }
        }
        y3 = re;
        ans[i] = dist(x1, y1, 0, re) - R;
        oor = ans[i];
    }
    while (l--) {
        int k;
        cin >> k;
        cout << k << " " << floor(ans[k]) << endl;
    }
}
