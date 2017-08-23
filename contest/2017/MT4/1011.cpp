//2017-08-16-15.55
//1011

#include <bits/stdc++.h>
using namespace std;

string a[10][7] = {
    {
        ".XX.",
        "X..X",
        "X..X",
        "....",
        "X..X",
        "X..X",
        ".XX.",
    },
    {
        "....",
        "...X",
        "...X",
        "....",
        "...X",
        "...X",
        "....",
    },
    {
        ".XX.",
        "...X",
        "...X",
        ".XX.",
        "X...",
        "X...",
        ".XX.",
    },
    {
        ".XX.",
        "...X",
        "...X",
        ".XX.",
        "...X",
        "...X",
        ".XX.",
    },
    {
        "....",
        "X..X",
        "X..X",
        ".XX.",
        "...X",
        "...X",
        "....",
    },
    {
        ".XX.",
        "X...",
        "X...",
        ".XX.",
        "...X",
        "...X",
        ".XX.",
    },
    {
        ".XX.",
        "X...",
        "X...",
        ".XX.",
        "X..X",
        "X..X",
        ".XX.",
    },
    {
        ".XX.",
        "...X",
        "...X",
        "....",
        "...X",
        "...X",
        "....",
    },
    {
        ".XX.",
        "X..X",
        "X..X",
        ".XX.",
        "X..X",
        "X..X",
        ".XX.",
    },
    {
        ".XX.",
        "X..X",
        "X..X",
        ".XX.",
        "...X",
        "...X",
        ".XX.",
    }
};
string in[7];
int check(int p) {
    for (int i = 0; i < 10; i++) {
        bool ok = true;
        for (int j = 0; j < 7; j++) {
            for (int k = 0; k < 4; k++) {
                if (in[j][k + p] != a[i][j][k]) {
                    ok = 0;
                    break;
                }
            }
            if (!ok) break;
        }
        if (ok) return i;
    }
    return -1;
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        for (int i = 0; i < 7; i++) {
            cin >> in[i];
        }
        cout << check(0) << check(5) << ':' << check(12) << check(17) << endl;
    }
}
