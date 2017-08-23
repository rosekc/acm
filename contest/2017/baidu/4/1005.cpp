//2017-08-18-16.05
//1005

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int maxn = 1e4 + 10;
const int mod = 1e9 + 7;
int d1[maxn][10], d2[maxn][10];

string in;

int cal() {
    memset(d1, 0, sizeof d1);
    memset(d2, 0, sizeof d2);
    int l = in.length();
    for (int i = 0; i < l; i++) {
        in[i] -= '0';
    }
    for (int i = 1; i < in[0]; i++) {
        d1[0][i] = 1;
    }
    int t = in[0];
    int cnt = 0;
    int f = 0;
    for (int i = 1; i < l; i++) {
        cnt = cnt * 10 % mod;
        for (int j = 0; j <= 9; j++) {
            for (int k = 0; k <= 9; k++) {
                if (k < j) {
                    d2[i][j] += d2[i - 1][k] + d1[i - 1][k];
                    d2[i][j] %= mod;
                } else if (k > j) {
                    d1[i][j] += d1[i - 1][k];
                    d1[i][j] %= mod;
                    cnt += d2[i - 1][k];
                    cnt %= mod;
                }
                d2[i][j] += d2[i - 1][j];
                d2[i][j] %= mod;
                d1[i][j] += d1[i - 1][j];
                d1[i][j] %= mod;
                if (j != 0) d1[i][j]++;
            }
        }
        if (f == 0) {
            if (in[i] <= t) {
                t = in[i];
                for (int j = 0; j < t; j++) {
                    d1[i][j]++;
                    d1[i][j] %= mod;
                }
            } else {
                f = 1;
                int en = in[i];
                for (int j = 0; j < en; j++) {
                    if (j <= t) d1[i][j]++, d1[i][j] %= mod;
                    else d2[i][j]++, d2[i][j] %= mod;
                }
                t = en;
            }
        } else if (f == 1) {
            if (in[i] < t) {
                f = 2;
                cnt += in[i];
                cnt %= mod;
            } else {
                cnt += t;
                cnt %= mod;
                int en = in[i];
                for (int j = t; j < en; j++) d2[i][j]++, d2[i][j] %= mod;
                t = en;
            }
        } else {
            cnt += in[i];
            cnt %= mod;
        }
    }
    if (f == 2) cnt++;
    long long ans = 0;
    for (int i = 0; i < l; i++) {
        ans = (ans * 10 + in[i]) % mod;
    }
    ans = ((ans - cnt) % mod + mod) % mod;
    return ans;
}

main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> in;
        cout << cal() << endl;
    }
}
