//2017-08-13-14.03
//1001

#include <bits/stdc++.h>

using namespace std;

int moc = 1e9 + 7;

long long d[1010][1010];

long long

long long get(int x, int y) {
    if (d[x][y] != 0) return d[x][y];
    if (x == 1) return d[x][y] = y;
    d[x][y] = (get(x - 1, y) * x) % mod
    return d[x][y];
}

int main() {
    int T, m, n;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        long long ans;
    }
}
