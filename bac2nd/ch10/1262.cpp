//2017-09-03-13.23
//Uva 1262

#include <bits/stdc++.h>

using namespace std;

char ans[7788][5];
int cnt;
vector<char> S[6];
char t[5];
void dfs(int i) {
    if (i == 5) {
        memcpy(ans[cnt++], t, sizeof(char) * 5);
        return;
    }
    if (cnt > 7780) return;
    for (char c : S[i]) {
        t[i] = c;
        dfs(i + 1);
        if (cnt > 7780) return;
    }
}

int main() {
    int T, k;
    string s;
    cin >> T;
    while (T--) {
        set<char> a[6], b[6];
        cnt = 0;
        cin >> k;
        for (int i = 0; i < 6; i++) {
            cin >> s;
            for (int j = 0; j < 5; j++) {
                a[j].insert(s[j]);
            }
        }
        for (int i = 0; i < 6; i++) {
            S[i] = vector<char>(6);
            cin >> s;
            for (int j = 0; j < 5; j++) {
                b[j].insert(s[j]);
            }
        }
        for (int i = 0; i < 5; i++) {
            auto it = set_intersection(a[i].begin(), a[i].end(), b[i].begin(), b[i].end(), S[i].begin());
            //cout << it - S[i].begin() << endl;
            S[i].resize(it - S[i].begin());
        }
        dfs(0);
        //cout << cnt << endl;
        if (k > cnt) cout << "NO" << endl;
        else {
            for (int i = 0; i < 5; i++) {
                putchar(ans[k - 1][i]);
            }
            putchar('\n');
        }
    }
}
