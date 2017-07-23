//2017-07-11-11.56
//POJ 1007

#include <iostream>
#include <algorithm>
using namespace std;

struct St {
    string s;
    int w;
    bool operator <(const St& b)const {
        return w < b.w;
    }
};

St A[105];

int cal(string &s, int l, int r, char* T) {
    //cout << l << " " <<r << endl;
    if (l >= r - 1) return 0;
    int m = (l + r) / 2;
    int p = l, q = m, i = l;
    int ans = cal(s, l, m, T) + cal(s, m, r, T);
    while (p < m || q < r) {
        if (q >= r || (p < m && s[p] <= s[q])) T[i++] = s[p++];
        else {
            T[i++] = s[q++];
            ans += (m - p);
            //cout << m << " " << p <<endl;
        }
    }
    for (i = l; i < r; i++) s[i] = T[i];
    //cout << ans << endl;
    return ans;
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        char t[n + 5];
        for (int i = 0; i < m; i++) {
            cin >> A[i].s;
            string tt = A[i].s;
            A[i].w = cal(tt, 0, n, t);
        }
        sort(A, A + m);
        for (int i = 0; i < m; i++) {
            //cout << A[i].s << " " << A[i].w << endl;
            cout << A[i].s << endl;
        }
    }
}
