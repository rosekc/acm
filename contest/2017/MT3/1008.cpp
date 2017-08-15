#include<bits/stdc++.h>
#define ll long long
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const ll mod = 1e9 + 7;
const int N = 5005;

ll f(ll a, ll b) {
    a = a % mod;
    ll ans = 1;
    while (b) {
        if (b & 1)
            ans = ans * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    ll a, b, cas = 1;
    while (cin >> a >> b) {
        cout << "Case #" << cas++ << ": " << f(a, b) << endl;
    }
} 
