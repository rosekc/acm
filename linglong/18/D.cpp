//2017-07-15-13.01
//D

#include <bits/stdc++.h>

using namespace std;

long long d[100000 + 10];
int n, a;
int b[100000 + 10];

long long cal(int i, int j) {
    int dis = b[i] - b[j];
    //cout << (1ll << dis) + a << endl;
    return (1ll << dis) + a;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> a;
        memset(d, 0x3f, sizeof d);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        n = unique(b, b + n) - b;
        d[0] = 0;
        for (int i = 1; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (j < i - 1 && pow(2, b[i] - b[j]) > a * (i - j)) break;
                d[i] = min(d[i], d[j] + cal(i, j));
            }
        }
//        for (int i = 0; i < n; i++) {
//            cout << d[i] << " ";
//        }
//        cout << endl;
        cout << d[n - 1] << endl;
    }
}
