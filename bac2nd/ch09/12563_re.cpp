//2017-07-12-22.49
//Uva 12563

#include <bits/stdc++.h>

using namespace std;

struct St {
    int cnt, tot;
    bool operator<(const St &b)const {
        if (cnt == b.cnt) return tot < b.tot;
        return cnt < b.cnt;
    }
    void operator =(const St &b) {
        cnt = b.cnt;
        tot = b.tot;
    }
};

int n, t;
St d[55][12000];
int a[55];



int main() {
    int T, kase = 1;
    cin >> T;
    while (T--) {
        cin >> n >> t;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < t; j++) {
                if  (j < a[i]) {
                    d[i][j] = d[i - 1][j];
                    continue;
                }
                St next_st = d[i - 1][j - a[i]];
                next_st.cnt++;
                next_st.tot += a[i];
                d[i][j] = max(d[i - 1][j], next_st);
            }
        }
//        for (int i = 0; i <= n; i++) {
//            for (int j = 0; j < t; j++) {
//                cout << d[i][j].cnt << " ";
//            }
//            cout << endl;
//        }
        printf("Case %d: %d %d\n", kase++, d[n][t - 1].cnt + 1, d[n][t - 1].tot + 678);
    }
}
