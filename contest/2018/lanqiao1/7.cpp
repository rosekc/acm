// 2018-03-28 17:47:09

#include <bits/stdc++.h>

using namespace std;

int n;
double a0, anp1;
double c;

int main() {
    cin >> n;
    cin >> a0 >> anp1;
    double p1 = 0, p2 = 0;
    for (int i = 1; i <= n; i++) {
        cin >> c;
        if (i == 1) p1 = 2 * c;
        else if (i == 2) p2 = 2 * p1 + 2 * c;
        else {
            double t = 2 * p2 - p1 + 2 * c;
            p1 = p2;
            p2 = t;
        }
    }
    cout << setprecision(2) << fixed << (anp1 + a0 * n - p2) / (n + 1) << endl;
}