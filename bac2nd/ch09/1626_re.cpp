//2017-07-23-16.16
//Uva 1626

#include <bits/stdc++.h>

using namespace std;

char in[105];
int d[105][105];

int dp(int i, int j) {
    int &ans = d[i][j];
    if (ans != -1) return ans;
    if (i > j) return ans = 0;
    if (i == j) return ans = 1;
    ans = 0x3f3f3f3f;
    if ((in[i] == '(' && in[j] == ')')
        || (in[i] == '[' && in[j] == ']')) {
        ans = min(ans, dp(i + 1, j - 1));
    }
    for (int p = i; p < j; p++) {
        ans = min(ans, dp(i, p) + dp(p + 1, j));
    }
    return ans;
}
void print(int i, int j) {
    if (i > j) return;
    if (i == j) {
        if (in[i] == '[' || in[j] == ']') cout << "[]";
        else cout << "()";
    }
    if (d[i][j] == 0) {
        for (int p = i; p <= j; p++) {
            cout << in[p];
        }
        return;
    }
    if ((in[i] == '(' && in[j] == ')')
        || (in[i] == '[' && in[j] == ']')) {
        if (d[i][j] == d[i + 1][j - 1]) {
            cout << in[i];
            print(i + 1, j - 1);
            cout << in[j];
            return;
        }
    }
    for (int p = i; p < j; p++) {
        if (d[i][j] == d[i][p] + d[p + 1][j]) {
            print(i, p);
            print(p + 1, j);
            return;
        }
    }
}

int main() {
    int T;
    cin >> T;
    getchar();
    while (T--) {
        memset(d, -1, sizeof d);
        gets(in);
        gets(in);
        int len = strlen(in);
        dp(0, len - 1);
        print(0, len - 1);
        cout << endl;
        if (T) cout << endl;
    }
}
