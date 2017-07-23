//2017-07-14-12.07
//C

#include <bits/stdc++.h>

using namespace std;

struct St {
    int cnt, lastvis;
};
set<int> s;
int a[2010], b[2020], sum[2020];

int main() {
    int n, k;
    cin >> k >> n;
    for (int i = 1; i <= k; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    int* su = sum + 1;
    sort(su, su + k);
    k = unique(su, su + k) - su;
    //cout << k << endl;
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        s.insert(b[i]);
    }
    auto it = s.begin();
    int cnt = 0;
    for (int i = 0; i <= k - n; i++) {
        int t = *it - su[i];
        int f = 0;
        for (int j = i; j < k; j++) {
            if (s.count(t + su[j])) f++;
        }
        if (f == n) cnt++;
    }
    cout << cnt << endl;
}
