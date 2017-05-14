//2017-04-30-13.17
//Uva 11584

#include <bits/stdc++.h>

using namespace std;

char a[1010];
int d[1010];
bool isp[1010][1010];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> a + 1;
        int len = strlen(a + 1);
        for (int i = 1; i <= len; i++) {
            bool f = 1;
            for (int j = 0; i - j > 0 && i + j <= len; j++) {
                if (f && a[i - j] == a[i + j]) isp[i - j][i + j] = 1;
                else {
                    isp[i - j][i + j] = 0;
                    f = 0;
                }
            }
            f = 1;
            for (int j = 0; i - j - 1 > 0 && i + j <= len; j++) {
                if (f && a[i - j - 1] == a[i + j]) isp[i - j - 1][i + j] = 1;
                else {
                    isp[i - j - 1][i + j] = 0;
                    f = 0;
                }
            }
        }
        d[1] = 0;
        for (int i = 1; i <= len; i++) {
            d[i] = 0x3f3f3f3f;
            for (int j = 0; j < i; j++) {
                if (isp[j + 1][i]) d[i] = min(d[i], d[j] + 1);
            }
        }
        cout << d[len] << endl;
    }
}
