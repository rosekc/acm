//2017-08-12-16.14
//1002

#include <bits/stdc++.h>

using namespace std;

const int maxn = 100000 + 100;

struct St {
    int d[maxn];
    int fa(int x) {
        return d[x] == x ? x : d[x] = fa(d[x]);
    }
    void connect(int i, int j) {
        d[i] = j;
    }
};
St a[2];
void reset() {
    memset(a[0].d, 0, sizeof a[0].d);
    memset(a[1].d, 0, sizeof a[1].d);
}

int main() {
    int L, i, j, e;
    int cnt = 0;
    vector<int> ans;
    cin >> L;
    while (L--) {
        cin >> i >> j >> e;
        cnt++;
        if (a[e].fa(i) != a[e].fa(j)) {
            if (a[!e].fa(i) != a[!e].fa(j)) a[e].connect(a[e].fa(i), a[e].fa(j));
            else {
                ans.push_back(cnt);
                cnt = 1;
                reset();
                a[e].connect(i, j);
            }
        }
    }
    cout << ans.size() + 1 << endl;
    for (int i : ans) {
        cout << i << endl;
    }
    cout << cnt << endl;
}

