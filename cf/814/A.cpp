//2017-06-07-19.43
//A

#include <bits/stdc++.h>

using namespace std;

int n, k, a[300], b[300], vis[300];

bool dfs(int cur, int curk) {
    if (curk == k) {
        int f = 0;
//        for (int i = 1; i <= n; i++) {
//            cout << a[i] << " ";
//        }
        for (int i = 2; i <= n; i++) {
            if (a[i] <= a[i - 1]) f = 1;
        }
        return f;
    }
    for (int i = cur + 1; i <= n; i++) {
        if (a[i] == 0) {
            for (int j = 1; j <= k; j++) {
                if (!vis[j]) {
                    vis[j] = j;
                    a[i] = b[j];
                    if (dfs(i, curk + 1)) return true;
                    vis[j] = 0;
                }
            }
            a[i] = 0;
            return false;
        }
    }
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int j = 1; j <= k; j++) {
        cin >> b[j];
    }
    if (dfs(0, 0)) puts("Yes");
    else puts("No");
}
