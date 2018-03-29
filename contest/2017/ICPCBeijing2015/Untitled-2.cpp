// 2017-11-19 22:48:09
// ??

#include <bits/stdc++.h>
using namespace std;

int main() {
    int f[] = {0, 2, 2, 1, 4, 5, 6};
    for (int i = 1; i <= 6; i++) {
        //if (i != f[i]) ans++;
        if (f[i] != i && f[f[i]] != f[i]) {
            cout << i << endl;
            cout << f[f[i]] << " " <<  f[i] <<endl;
            cout << "gg";
            return 0;
        }
    }
}