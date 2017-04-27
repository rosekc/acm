//2017-04-22-13.32
//A

#include <bits/stdc++.h>

using namespace std;

int d1[] = {0, 1, 0, 1, -1};
int d2[] = {0, 0, 1, 1, -1};

int main() {
    int T, n, t;
    cin >> T;
    while (T--) {
        int kou = 0, toh = 0;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> t;
            kou += d1[t];
            toh += d2[t];
        }
        //cout << kou << " " << toh;
        if (kou == toh) puts("Draw");
        else if (kou < toh) puts("Tohru");
        else puts("Kobayashi");
    }
}
