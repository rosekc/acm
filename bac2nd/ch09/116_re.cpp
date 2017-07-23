#include <bits/stdc++.h>

using namespace std;

int d[15][105], a[15][105];
int m, n;

int main() {
    while (cin >> m >> n) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
                if (j == n - 1) d[i][j] = a[i][j];
            }
        }
        for (int j = n - 2; j >= 0; j--) {
            for (int i = 0; i < m; i++) {
                d[i][j] = min(d[(i - 1 + m) % m][j + 1], min(d[i][j + 1],
                        d[(i + 1) % m][j + 1])) + a[i][j];
            }
        }
//        cout << endl;
//        for (int i = 0; i < m; i++) {
//            for (int j = 0; j < n; j++) {
//                cout << d[i][j] << " ";
//            }
//            cout << endl;
//        }
        int ans = 0x3f3f3f3f, ind;
        for (int i = 0; i < m; i++) {
            if (ans > d[i][0]) {
                ans = d[i][0];
                ind = i;
            }
        }
        cout << ind + 1;
        int j = 1;
        while (j != n) {
            vector<int> next;
            for (int i = -1; i <= 1; i++) {
                next.push_back((ind + i + m) % m);
            }
            sort(next.begin(), next.end());
            for (auto i : next) {
                if (d[i][j] == d[ind][j - 1] - a[ind][j - 1]) {
                    ind = i;
                    cout << " " << ind + 1;
                    break;
                }
            }
            j++;
        }
        cout << endl << ans  << endl;
    }
}
