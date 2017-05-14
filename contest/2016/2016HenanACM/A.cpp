//2017-05-01-14.04
//A

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1010;
char in[maxn];

int built(int,int);

int cal(int i) {
    int re = 0;
    while (i >= 10) {
        re += i % 10;
        i /= 10;
    }
    return re + i;
}

int Smax(int l) {
    int p, r;
    for (int i = l;; i++) {
        if (in[i] == ',') {
            p = i;
        }
        if (in[i] == ')') {
            r = i;
            break;
        }
    }

    return max(cal(built(l, p)), cal(built(p + 1, r)));
}

int built(int l, int r) {
    int p = 0;
    int pp = -1, pm = -1, ps = -1;
    for (int i = l; i < r; i++) {
        if (in[i] == '(') p++;
        else if (in[i] == ')') p--;
        if (!p) {
            if (in[i] == '*') pm = i;
            if (in[i] == '+') pp = i;
            if (in[i] == 'S') ps = i;
        }
    }
    if (pp == -1 && pm == -1 && ps == -1) {
        if (in[l] == '(') return built(l + 1, r - 1);
        else return atoi(&in[l]);
    }
    if (pp != -1) {
        return built(l, pp) + built(pp + 1, r);
    }
    if (pm != -1) {
        return built(l, pm) * built(pm + 1, r);
    }
    if (ps != -1) {
        return Smax(l + 5);
    }
}



int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> in;
        cout << built(0, strlen(in)) << endl;
    }
}
