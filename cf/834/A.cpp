//2017-07-30-22.36
//A

#include <bits/stdc++.h>

using namespace std;

char s[] = "v<^>";

string a, b;

int main() {
    int n;
    cin >> a >> b >> n;
    n %= 4;
    int p;
    for (int i = 0; i < 4; i++) {
        if (a[0] == s[i]) p = i;
    }
    if (s[(p + n) % 4] == b[0] && s[(p - n + 4) % 4] == b[0]) {
        puts("undefined");
    }else if (s[(p - n + 4) % 4] == b[0]) {
        puts("ccw");
    }else if (s[(p + n) % 4] == b[0]) {
        puts("cw");
    }else puts("undefined");
}
