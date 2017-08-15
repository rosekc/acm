//2017-07-24-23.01
//B

#include <bits/stdc++.h>

using namespace std;

int n;
int pos;
string in, pat;
bool good['a' + 26];

bool check1() {
    for (int i = 0; i < pos; i++) {
        //cout << pat[i] << " " << in[i] << endl;
        if (pat[i] == '?' && !good[in[i]]) return 0;
        else if (pat[i] != '?' && in[i] != pat[i]) {
            //puts("???");
            return 0;
        }
    }
    return true;
}

bool check2() {
    for (int i = in.length(), j = pat.length(); j != pos; i--, j--) {
        if (pat[j] == '?' && !good[in[i]]) return false;
        else if (pat[j] != '?' && in[i] != pat[j]) return 0;
    }
    return 1;
}
bool check3() {
    //cout << (int)in.length() - ((int)pat.length() - pos) << endl;
    for (int i = pos; i <= (int)in.length() - ((int)pat.length() - pos); i++) {
        if (good[in[i]]) return 0;
    }
    return 1;
}

int main() {
    cin >> in >> pat >> n;
    memset(good, 0, sizeof good);
    for (int i = 0; i < in.length(); i++) {
        good[in[i]] = 1;
    }
    pos = -1;
    bool found = 1;
    for (int i = 0; i < pat.length(); i++) {
        if (pat[i] == '*') {
            pos = i;
            break;
        }
    }
    if (pos == -1) {
        found = 0;
    }
    while (n--) {
        cin >> in;
        if (!found) {
            pos = in.length();
            if (in.length() == pat.length() && check1()) puts("YES");
            else puts("NO");
            continue;
        }
        if (in.length() < (int)pat.length() - 1) {
            puts("NO");
            continue;
        }
//                cout << check1() << endl;
//                cout << check2() << endl;
//                cout << check3() << endl;
        if (check1() && check2() && check3()) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
}
