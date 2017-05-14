//2017-05-14-14.06
//Uva 1626

#include <bits/stdc++.h>

using namespace std;

const int maxn = 100 + 10;
int d[maxn][maxn];
char buf[maxn];

bool check(char i, char j) {
    return (i == '(' && j == ')') || (i == '[' && j == ']');
}

void print(int i, int j) {
    //cout << i << " " <<j << endl;
    if (i > j) return;
    if (d[i][j] == 0) {
        for (int k = i; k <= j; k++) {
            cout << buf[k];
        }
        return;
    }
    if (i == j) {
        if (buf[i] == '[' || buf[i] == ']') cout << "[]";
        else cout << "()";
        return;
    }
    if (check(buf[i], buf[j]) && d[i + 1][j - 1] == d[i][j]) {
        cout << buf[i];
        print(i + 1, j - 1);
        cout << buf[j];
        return;
    }
    for (int k = i; k < j; k++) {
        if (d[i][k] + d[k + 1][j] == d[i][j]) {
            print(i, k);
            print(k + 1, j);
            return;
        }
    }
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int T;
    cin >> T;
    getchar();
    while (T--) {
        cin.getline(buf, maxn);
        cin.getline(buf, maxn);
        int len = strlen(buf);
        for (int i = 0; i < len; i++) {
            d[i][i] = 1;
            d[i + 1][i] = 0;
        }
        for (int i = len - 1; i >= 0; i--) {
            for (int j = i + 1; j < len; j++) {
                int &ans = d[i][j] = len;
                if (check(buf[i], buf[j])) ans = min(ans, d[i + 1][j - 1]);
                for (int k = i; k < j; k++) {
                    ans = min(ans, d[i][k] + d[k + 1][j]);
                }
            }
        }
        print(0, len - 1);
        cout << endl;
        if (T) cout << endl;
    }
}
