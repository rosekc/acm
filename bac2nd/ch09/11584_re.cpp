//2017-07-13-11.36
//Uva 11584

#include <bits/stdc++.h>

using namespace std;

string in;

int d[1010];
bool isp[1010][1010];

void cal() {
    memset(isp, 0, sizeof isp);
    int len = in.length();
    for (int i = 0; i < len; i++) {
        for (int j = 0;; j++) {
            if (i + j < len && i - j >= 0 &&
                    in[i + j] == in[i - j]) isp[i - j][i + j] = 1;
            else break;
        }
        for (int j = 1;; j++) {
            if (i + j < len && i - j + 1 < len &&
                    i - j + 1 >= 0 && in[i + j] == in[i - j + 1])
                    isp[i - j + 1][i + j] = 1;
            else break;
        }
    }
    d[0] = 1;
    for (int i = 1; i < len; i++) {
        if (isp[0][i]) {
            d[i] = 1;
            continue;
        }
        d[i] = d[i - 1] + 1;
        for (int j = i - 1; j > 0; j--) {
            if (isp[j][i]) d[i] = min(d[i], d[j - 1] + 1);
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> in;
        cal();
//        for (int i = 0; i < in.length(); i++) {
//            for (int j = 0; j < in.length(); j++) {
//                cout << isp[i][j] << " " ;
//            }
//            cout << endl;
//        }
//        for (int i = 0; i < in.length(); i++) {
//            cout << d[i] << endl;
//        }
        cout << d[in.length() - 1] << endl;
    }
}
