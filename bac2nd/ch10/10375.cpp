//2017-08-27-17.17
//Uva 10375

#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e4 + 100;
int vis[maxn], e[maxn];

vector<int> prime;

void init() {
    int m = sqrt(maxn + .5);
    for (int i = 2; i <= maxn; i++) {
        if (!vis[i]) {
            //cout << i << endl;
            prime.push_back(i);
            for (int j = i * i; j <= maxn; j += i) {
                vis[j] = 1;
            }
        }
    }
}

void add_integer(int n, int d) {
    for (int i = 0; i < prime.size(); i++) {
        while (n % prime[i] == 0) {
            n /= prime[i];
            e[i] += d;
        }
        if (n == 1) break;
    }
}

void add_factorial(int n, int d) {
    for (int i = 1; i <= n; i++) {
        add_integer(i, d);
    }
}

int main() {
    init();
    int p, q, r, s;
    while (cin >> p >> q >> r >> s) {
        memset(e, 0, sizeof e);
        add_factorial(p, 1);
        add_factorial(p - q, -1);
        add_factorial(q, -1);
        add_factorial(r, -1);
        add_factorial(r - s, 1);
        add_factorial(s, 1);
        double ans = 1;
        for (int i = 0; i < prime.size(); i++) {
            //cout << prime[i] << ' ' << e[i] << endl;
            ans *= pow(prime[i], e[i]);
        }
        cout << setprecision(5) << fixed << ans << endl;
    }
}
