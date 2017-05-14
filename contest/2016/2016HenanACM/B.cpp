#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000000 + 10;
int d[maxn];
const int MOD = 997;
int cal(int i) {
    if (i < 0) return 0;
    if (d[i] != -1) return d[i];
    int re = 0;
    //re += (cal(i - 1) * 2) % MOD;
    //re %= MOD;

    for (int j = 1; j < i; j++) {
        re += (cal(j) * cal(i - j)) % MOD;
        re %= MOD;
    }
    //cout << i << "  " <<re << endl;
    return d[i] = re;
}

int main()
{
    memset(d, -1, sizeof d);
    d[0] = 1;
    d[1] = 1;
    d[2] = 5;
    lim = maxn;
    dfs(0, 0);
    int T;
    cin >> T;
    while (T--) {
        int n, m, k;
        cin >> n >> m >> k;
        cout << cal(m - 1) << " " << cal(n - m - k + 1) << endl;
    }
}
