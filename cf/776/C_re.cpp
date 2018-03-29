//2017-10-22-23.27
//C

#include <bits/stdc++.h>

using namespace std;

map<long long, long long> mp;
vector<long long> ks;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, a;
    long long k, t;
    cin >> n >> k;
    t = 1;
    while (1) {
        if (abs(t) > 1e15) break;
        ks.push_back(t);
        t *= k;
        if (t == 1) break;
    }
    long long ans = 0;
    for (long long j : ks) {
        mp[j]++;
    }
    long long sum, last_sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        sum = last_sum + a;
        ans += mp[sum];
        for (long long j : ks) {
            mp[sum + j]++;
        }
        last_sum = sum;
    }
    cout << ans << endl;
}
