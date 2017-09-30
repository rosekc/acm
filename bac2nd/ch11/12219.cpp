//2017-09-04-13.56
//Uva 12219

#include <bits/stdc++.h>

using namespace std;

const int maxn = 50000 + 100;
tuple<string, int, int> node[maxn];
map<tuple<string, int, int>, int> id;
int cnt, kase, p;
int vis[maxn];
string s;
int parse() {
    int curid = cnt++;
    int l, r;
    l = r = -1;
    string a = "";
    while (isalpha(s[p])) {
        a.push_back(s[p++]);
    }
    if (s[p] == '(') {
        p++;
        l = parse();
        p++;
        r = parse();
        p++;
    }
    auto tu = make_tuple(a, l, r);
    node[curid] = tu;
    if (id.count(tu)) {
        cnt--;
        return id[tu];
    }
    return id[tu] = curid;
}

void print(int c) {
    //cout << c << endl;
    if (vis[c] == kase) {
        cout << c + 1;
        //puts("123");
        return;
    }
    vis[c] = kase;
    int l, r;
    string expr;
    tie(expr, l, r) = node[c];
    cout << expr;
    if (l == -1) {
        return;
    }
    cout << "(";
    print(l);
    cout << ",";
    print(r);
    cout << ")";
}

int main() {
    int T;
    cin >> T;
    for (kase = 1; kase <= T; kase++) {
        cin >> s;
        id.clear();
        cnt = 0;
        p = 0;
        print(parse());
        cout << endl;
//        for (auto i : id) {
//            int l, r;
//            string expr;
//            tie(expr, l, r) = i.first;
//            cout << expr << " " << l << " " << r << " " << i.second << endl;
//        }
    }
}
