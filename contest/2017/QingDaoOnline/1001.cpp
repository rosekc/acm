//2017-09-17-14.55
//1001

#include <bits/stdc++.h>

using namespace std;

int main() {
    double x1, y1, x2, y2, x3, y3, x4, y4;
    int T;
    cin >> T;
    while (T--) {
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        double a = 2 * (x2 - x1);
        double b = 2 * (y2 - y1);
        double c = x2 * x2 + y2 * y2 - x1 * x1 - y1 * y1;
        double d = 2 * (x3 - x2);
        double e = 2 * (y3 - y2);
        double f = x3 * x3 + y3 * y3 - x2 * x2 - y2 * y2;
        double x = (b * f - e * c) / (b * d - e * a);
        double y = (d * c - a * f) / (b * d - e * a);
        //r = sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1));
        //        double zx = (x1 + x2 + x3) / 3.0;
        //        double zy = (y1 + y2 + y3) / 3.0;
        double l = (x4 - x) * (x4 - x) + (y4 - y) * (y4 - y);
        double r = (x1 - x) * (x1 - x) + (y1 - y) * (y1 - y);
        cout << x << " " << y << endl;
        cout << l << " " << r << endl;
        if (l > r) {
            puts("Accepted");
        } else {
            puts("Rejected");
        }
    }
}
