#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll p[6], q[6];

ll to_int(char *s, int l) {
    ll re = 0;
    for (int i = 0; i != l; i++) {
        re *= 10;
        re += (s[i] - '0');
    }
    return re;
}
char s[30];
int len;
ll ans;
void cal() {
    char* ss = s;
    for (int i = 0; i < 5; i++) {
        //cout << to_int(ss, p[i]) << endl;
        q[i] = to_int(ss, p[i]);
        ss = ss + p[i];
    }
    //    cout << q[0] << " " << q[1] << " " << q[2] << " " << q[3] << " "
    //    << q[4] << endl;
    //    cout << q[0] + q[1] - q[2] * q[3] / q[4] << endl;
    ans = max(ans, q[0] + q[1] - q[2] * q[3] / q[4]);

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //cout << to_int("123", 3) << endl;
    int T, kase = 0;
    cin >> T;
    while (T--) {
        cin >> s;
        len = strlen(s);
        ans = -1e15;
        //cout << ans << endl;
        p[3] = p[2] = 1;
        for (int i = 1; i <= 3; i++) {
            p[4] = i;
            p[0] = 1;
            p[1] = len - 3 - i;;
            cal();
            p[1] = 1;
            p[0] = len - 3 - i;;
            cal();
        }
        cout << "Case #" << ++kase << ": " << ans << endl;
    }
}
