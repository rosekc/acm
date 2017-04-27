//2017-04-23-12.44
//D

#include <bits/stdc++.h>

using namespace std;

char d[] = " QWERTYUIOP ASDFGHJKL ZXCVBNM ";

int main()
{
    char in[50];
    int T;
    cin >> T;
    int len = strlen(d);
    getchar();
    while (T--) {
        gets(in);
        int re;
        for (int i = 0; i < len; i++) {
            if (d[i] == in[0]) {
                if (in[2] == 'R') re = i + 1;
                else re = i - 1;
                break;
            }
        }
        if (d[re] == ' ') puts("No letter.");
        else cout << d[re] << endl;
    }
}
