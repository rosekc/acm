//2017-09-04-22.46
//B

#include <bits/stdc++.h>

using namespace std;

long long dist(long long x1, long long y1, long long x2, long long y2) {
    return abs(x1 - x2) * abs(x1 - x2) + abs(y1 - y2) * abs(y1 - y2);
}

int main() {
    long long x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    long long ab = dist(x1, y1, x2, y2);
    long long bc = dist(x2, y2, x3, y3);
    long long ac = dist(x1, y1, x3, y3);
    //cout << ac << " " << ab << " " << bc << endl;
    if (ab == bc && !((x1 + x3) == 2 * x2 && (y1 + y3) == 2 * y2))  puts("Yes");
    else puts("No");
}
