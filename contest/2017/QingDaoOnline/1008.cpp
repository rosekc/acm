//2017-09-17-12.23
//1008

#include <bits/stdc++.h>

using namespace std;

string li[] = {
    "rat", "ox", "tiger",
    "rabbit", "dragon", "snake",
    "horse", "sheep", "monkey",
    "rooster", "dog", "pig"
};

int main() {
    int T;
    string a, b;
    cin >> T;
    while (T--) {
        cin >> a >> b;
        int p1, p2;
        p1 = p2 = 0;
        //cout << a << b << endl;
        while (li[p1] != a) {
            p1++;
            //cout << (li[p1] == a) << endl;
        }
        while (li[p2] != b) {
            p2++;
            //cout << p2 << endl;
        }
        //cout << p1 << " " << p2 << endl;
        if (p1 == p2) cout << 12 << endl;
        else if (p1 > p2) cout << 12 - p1 + p2 << endl;
        else cout << p2 - p1 << endl;
    }
}
