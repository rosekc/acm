//2017-04-23-13.02
//I

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin >> T;
    string a, b;
    while (T--) {
        int ia = -1, ib = -1;
        cin >> a >> b;
        set<char> vis;
        bool f = 0;
        for (int i = 0; i < a.length(); i++) {
            if (vis.count(a[i])) f = 1;
            vis.insert(a[i]);
            if (a[i] != b[i]) {
                if (ia == -1) ia = i;
                else if (ib == -1) ib = i;
                else {
                    ib = -2;
                    break;
                }
            }
        }
        if (ib >= 0 || (ia == -1 && ib == -1 && f)) puts("YES");
        else puts("NO");
    }
}
