//2017-08-01-15.18
//1008

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 500;
//线性筛法求莫比乌斯函数
bool check[MAXN + 10];
int prime[MAXN + 10];
int mu[MAXN + 10];
void Moblus() {
    memset(check, false, sizeof(check));
    mu[1] = 1;
    int tot = 0;
    for (int i = 2; i <= MAXN; i++) {
        if ( !check[i] ) {
            prime[tot++] = i;
            mu[i] = -1;
        }
        for (int j = 0; j < tot; j++) {
            if (i * prime[j] > MAXN) break;
            check[i * prime[j]] = true;
            if ( i % prime[j] == 0) {
                mu[i * prime[j]] = 0;
                break;
            } else {
                mu[i * prime[j]] = -mu[i];
            }
        }
    }
}

const int mod = 1e9 + 7;
int main() {
    for (int i = 1; i <= MAXN; i++) {
        cout << mu[i] <<  " ";
    }
    cout << endl;
    for (int n = 1; n <= 5; n++) {
        for (int k = 1; k <= 5; k++) {
            int nk = pow(n, k);
            int ret = 0;
            for (int i = 1; i <= nk; i++) {
                ret += (mu[i] * mu[i] * floor(sqrt(1.0 * nk / i)));
                ret %= mod;
            }
            cout << ret << " ";
        }
        cout << endl;
    }
}
