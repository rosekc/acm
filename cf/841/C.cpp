//2017-08-18-23.51
//C

#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
int a[maxn];
pair<int, int> b[maxn];
int rankb[maxn];
int main() {
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i].first;
        b[i].second = i;
    }
    sort(a, a + m);
    sort(b, b + m);
    for (int i = 0, j = m - 1; i < m; i++) {
        rankb[b[i].second] = j--;
    }
    for (int i = 0; i < m; i++) {
        //cout << rankb[i] << endl;
        cout << a[rankb[i]] << ' ';
    }
    cout << endl;
}
