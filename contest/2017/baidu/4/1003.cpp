//2017-08-18-14.53
//1003

#include <bits/stdc++.h>
using namespace std;

const int maxn = 10000 + 10;
const int mod =  1000000007;

;
long long d1[maxn];
long long d2[maxn];

int main()
{
    int T, n;
    cin >> T;
    d1[1] = d2[1] = 1;
    d1[2] = 6;
    d2[2] = 2;
    for (int i = 3; i < maxn; i++)
    {
        d2[i] = ((2 * d2[i - 1]) % mod);
        d1[i] += ((2 * d1[i - 1]) % mod);
        d1[i] %= mod;
        d1[i] += d2[i];
        d1[i] %= mod;
        d1[i] += (4 * d1[i - 2]) % mod;
        d2[i] %= mod;
    }
    while (T--)
    {
        cin >> n;
        if (n == 1) {
            cout << 2 << endl;
            continue;
        }
        long long ans = (4 * d1[n]) % mod;
        for (int i = 2; i < n; i++)
        {
            ans += (((8 * d1[i - 1]) % mod * d2[n - i]) % mod + ((8 * d1[n - i]) % mod * d2[i - 1]) % mod) % mod;
            ans %= mod;
        }
        cout << ans << endl;
    }
}
