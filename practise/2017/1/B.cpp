//2017-09-23-19.37
//B

#include <bits/stdc++.h>

using namespace std;

long long dist(long long x1, long long y1, long long x2, long long y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main() {
    long long x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    if (dist(x1, y1, x2, y2) == dist(x2, y2, x3, y3)
        && !((x1 + x3) == x2 * 2 && (y1 + y3) == y2 * 2)) {
            puts("Yes");
        }else puts("No");
}
