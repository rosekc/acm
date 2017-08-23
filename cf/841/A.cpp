//2017-08-18-23.04
//

#include <bits/stdc++.h>
using namespace std;

int a[26];

int main() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    for (int i = 0; i < s.length(); i++) {
        a[s[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        //cout << a[i] << ' ' << k << endl;
        if (a[i] > k) {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
}
