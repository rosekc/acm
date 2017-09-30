//2017-09-25-19.36
//D

#include <bits/stdc++.h>

using namespace std;

const int maxn = 200000 + 100;
int a[maxn];
int cnt[maxn];
bool vis[maxn];
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    int p = 1;
    while (p <= n && cnt[p]) p++;
    int ans= 0;
    //cout << c << " " << t<<endl;
    for (int i = 1; i <= n; i++) {
        if (cnt[a[i]] > 1) {
            // cout << vis[a[i]] <<endl;
            if (a[i] < p && !vis[a[i]]) {
                vis[a[i]] = 1;
                continue;
            }
            cnt[a[i]]--;
            a[i] = p;
            cnt[p]++;
            ans++;
            while (p <= n && cnt[p]) p++;
        }
    }
    //cout <<t <<endl;
    cout << ans << endl;
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}
