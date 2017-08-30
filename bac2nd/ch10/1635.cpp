//2017-08-27-22.54
//Uva 1635

#include <bits/stdc++.h>
using namespace std;

vector<int> prime;
const int maxm = 1e9 + 10;
const int maxn = 1e5 + 10;
vector<int> get_prime_factor(int n) {
    vector<int> primes;
    int m = sqrt(n + .5);
    for (int i = 2; i <= m; i++) {
        if (n % i == 0) {
            n /= i;
            primes.push_back(i);
            while (n % i == 0) n /= i;
        }
    }
    if (n > 1) primes.push_back(n);
    return primes;
}

bool bad[maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    while (cin >> n >> m) {
        auto primes = get_prime_factor(m);
        memset(bad, 0, sizeof bad);
        n--;
        for (int i : primes) {
            int min_e = 0;
            int t = m;
            while (t % i == 0) {
                t /= i;
                min_e++;
            }
            int e = 0;
            for (int k = 1; k < n; k++) {
                t = n - k + 1;
                while (t % i == 0) {
                    e++;
                    t /= i;
                    //puts("1561");
                }
                t = k;
                while (t % i == 0) {
                    e--;
                    t /= i;
                    //puts("4546");
                }
                if (e < min_e) {
                    bad[k] = 1;
                }
                //puts("15456");
            }
        }
        //puts("1231");
        vector<int> ans;
        for (int i = 1; i < n; i++) {
            if (!bad[i]) {
                ans.push_back(i + 1);
            }
        }
        cout << ans.size() << endl;
        bool first = 1;
        for (int i : ans) {
            if (!first) cout << ' ';
            cout << i;
            first = 0;
        }
        cout << endl;
    }
}
