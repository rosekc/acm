//2017-09-10-13.03
//1005

#include <bits/stdc++.h>

using namespace std;

int a[200];
int k;
int t = 0;
bool dfs(int c, int d) {
    if (d == k) {
        cout << c << endl;
        //if (c >= t + 2) return 1;
        //t = c;
        return 0;
    }
    for (int i = 0; i < 20; i++) {
        if (dfs(c + a[i], d + 1)) return 1;
    }
}
int main() {
    a[1]=1;
    for (int i = 2; i < 200; i++) {
        a[i] = a[i - 1] + a[i - 2];
    }
    while (cin >> k) {
        t = 0;
        dfs(0, 0);
    }
}
