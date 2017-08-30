//2017-08-24-12.13
//1001

#include <bits/stdc++.h>
using namespace std;

int cp[] = {0, 1, 3, 6, 10, 15};

unordered_map<string, int> m;

string mov(string s, int i, int j, int f) {
    swap(s[cp[i] + j], s[cp[i + 1] + j + f]);
    return s;
}

string read() {
    int t;
    string ret;
    for (int i = 0; i < 21; i++) {
        cin >> t;
        ret += (t + '0');
    }
    return ret;
}
queue<string> q;
int main() {
    m["011222333344444555555"] = 0;
    q.push("011222333344444555555");
    while (!q.empty()) {
        string c = q.front();
        q.pop();
        //cout << c << endl;
        for (int i = 0; i <= 5; i++) {
            for (int j = 0; j <= i; j++) {
                int k = 0;
                string ns = mov(c, i, j, k);
                if (!m.count(ns)) {
                    m[ns] = m[c] + 1;
                    if (m[ns] <= 3) q.push(ns);
                }
                k = 1;
                ns = mov(c, i, j, k);
                if (!m.count(ns)) {
                    m[ns] = m[c] + 1;
                    if (m[ns] <= 3) q.push(ns);
                }
            }
        }
    }
}
