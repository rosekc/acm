#include <bits/stdc++.h>

using namespace std;

bool open[1010];

int main() {
    int cnt = 1000;
    for (int i = 1; i <= 1000; i++) {
        if (i % 3 == 0) {
            if (open[i]) {
                cnt--;
                open[i] = 0;
            } else {
                cnt++;
                open[i] = 1;
            }
        }
        if (i % 5 == 0) {
            if (open[i]) {
                cnt--;
                open[i] = 0;
            } else {
                cnt++;
                open[i] = 1;
            }
        }
        if (i % 7 == 0) {
            if (open[i]) {
                cnt--;
                open[i] = 0;
            } else {
                cnt++;
                open[i] = 1;
            }
        }
    }
    cout << cnt;
}