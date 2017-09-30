//2017-09-23-22.42
//C

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    if (n == 2 && m == 0) {puts("NO"); return 0;}
    puts("YES");
    if (n == 1) {
        cout << m << endl;
        return 0;
    }
    if (n == 2) {
        cout << "0 " << m << endl;
        return 0;
    }
    if (n == 3) {
        int a = (1 << 18);
        cout << (m^((1<<19) - 1)) << " " << a << ' ' << a - 1 << endl;
    }
    if (n >= 4) {
        int t = 0;
        for (int i = 1; i <= n - 3; i++) {
            cout << i << " ";
            t ^= i;
        }
        int p = t ^ m;
        int a = (1 << 18);
        cout << (p^((1<<19) - 1)) << " " << a << ' ' << a - 1 << endl;
    }
}
