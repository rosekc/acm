//2017-07-13-23.19
//B

#include <bits/stdc++.h>

using namespace std;

string s1, s2, s3;
unordered_map<char, char> m;

int main() {
    cin >> s1 >> s2 >> s3;
    for (int i = 0; i < 26; i++) {
        m[s1[i]] = s2[i];
    }
    for (int i = 0; i < s3.length(); i++) {
        if (s3[i] >= 'A' && s3[i] <= 'Z') {
            cout << char(m[char(s3[i] - 'A' + 'a')] - 'a' + 'A');
        }else if (s3[i] < 'a') {
            cout << s3[i];
        }else {
            cout << m[s3[i]];
        }
    }
    cout << endl;
}
