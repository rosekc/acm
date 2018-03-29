// 2018-03-29 15:04:58

#include <bits/stdc++.h>

using namespace std;

int g[28][28];

int main() {
    string S, T;
    string a, b;
    int k;
    cin >> S >> T >> k;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            if (i == j) g[i][j] = 0;
            else g[i][j] = 999999;
        }
    }
    for (int i = 0; i < k; i++) {
        cin >> a >> b;
        g[a[0] - 'a'][b[0] - 'a'] = min(1, g[a[0] - 'a'][b[0] - 'a']);
    }
    for (int p = 0; p < 26; p++) {
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                g[i][j] = min(g[i][p] + g[p][j], g[i][j]);
            }
        }
    }
    // for (int i = 0; i < 26; i++) {
    //     for (int j = 0; j < 26; j++) {
    //         cout << g[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    int cnt = 0;
    for (int i = 0; i < S.length(); i++) {
        if (g[int(S[i] - 'a')][int(T[i] - 'a')] > 30) {
            cnt = -1;
            break;
        }
        cnt += g[int(S[i] - 'a')][int(T[i] - 'a')];
    }
    cout << cnt << endl;
}