//2017-09-04-00.00
//Uva 1636

#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    while (cin >> s) {
        int a, b;
        a = b = 0;
        int l = s.length();
        for (int i = 0; i < l; i++) {
            if (s[i] == '0') {
                if (s[(i + 1 + l) % l] == '0') {
                    a++;
                }
                b++;
            }
        }
        if (a * l > b * b) {
            puts("SHOOT");
        }else if(a * l < b * b) {
            puts("ROTATE");
        }else {
            puts("EQUAL");
        }
    }
}
