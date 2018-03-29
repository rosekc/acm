#include <bits/stdc++.h>

using namespace std;

int main() {
    int cnt = 0;
    for (int i = 10; i <= 99; i++) {
        for (int j = 10; j <= 99; j++) {
            if ((j / 10 + j % 10) * 2 == i && j == (i / 10 + i % 10) * 3)
                cnt++;
        }
    }
    cout << cnt;
}