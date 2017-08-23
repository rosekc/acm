//2017-08-22-14.13
//1010

#include <bits/stdc++.h>
using namespace std;

char reg[20000];
char buf[20];
int main() {
    int T;
    cin >> T;
    getchar();
    while (T--) {
        string s1;
        getline(cin, s1);
        string s2 ;
        getline(cin, s2);
        int cnt = 1;
        int p = 0;
        for (int i = 0; i < s2.length(); i++) {
            if (s2[i] == '.' && i + 1 < s2.length() && s2[i + 1] == '*') {
                reg[p++] = '(';
                reg[p++] = '.';
                reg[p++] = ')';
                reg[p++] = '?';//不加居然能过。。
                reg[p++] = '\\';
                //reg[p++] = '\\';
                sprintf(buf ,"%d", cnt++);
                int l = strlen(buf);
                for (int j = 0; j < l; j++) {
                    reg[p++] = buf[j];
                }
                reg[p++] = '*';
                i++;
            }else {
                reg[p++] = s2[i];
            }
        }
        reg[p++] = '\0';
        //cout << reg << endl;
        auto re = regex(reg);
        if (regex_match(s1, re)) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}
