//2017-08-02-16.00
//1118

#include <iostream>
#include <cmath>


const double eps = 1e-6;

using namespace std;

struct Point {
    double x, y;
};
typedef Point Vector;
//向量+向量=向量
Vector operator +(const Vector &a, const Vector &b) {
    return {a.x + b.x, a.y + b.y};
}
//点-点=向量
Vector operator -(const Vector &a, const Vector &b) {
    return {a.x - b.x, a.y - b.y};
}
//叉积
double operator ^(const Vector &a, const Vector &b) {
    return a.x * b.y - a.y * b.x;
}
//点积
double operator *(const Vector &a, const Vector &b) {
    return a.x * b.x + a.y * b.y;
}
Vector operator *(const Vector &a, const double &b) {
    return {a.x * b, a.y * b};
}
bool operator == (const Point &a, const Point &b) {
    return dcmp(a.x - b.x) == 0 && dcmp(a.y - b.y);
}

Point a[800];

int main() {
    int n, x, y;
    while (cin >> n && n) {
        for (int i = 0; i < n; i++) {
            cin >> a[i].x >> a[i].y;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int cnt = 0;
                Vector v1 = a[i] - a[j];
                for (int k = j + 1; k < n; k++) {
                    Vector v2 = a[i] - a[k];
                    int k1 = v1.x * v2.y;
                    int k2 = v1.y * v2.x;
                    if (k1 == k2) {
                        cnt++;
                    }
                    //为什么不用下面？
                    //double k1 = v1.x / v2.x;
                    //double k2 = v1.y / v2.y;
                    //if (dcmp(k1 - k2) == 0) {
                    //    cnt++;
                    //}
                }
                ans = max(ans, cnt);
            }
        }
        cout << ans + 2 << endl;
    }
}
