//2017-04-22-13.41
//B

#include <bits/stdc++.h>

using namespace std;

int d[105];

int main()
{
    int T, n, t;
    cin >> T;
    while (T--) {
        cin >> n;
        bool f = 1;
        int cnt1 = 0;
        for (int i = 0; i < n; i++) {
            cin >> d[i];
            if (d[i] == 1) {
                cnt1++;
            }
        }
        if (n < 10 || n > 13) {
            puts("No");
            continue;
        }
        sort(d, d + n);
        for (int i = 0; i < n - 1; i++) {
            if (d[i] < 1) {
                f = 0;
                break;
            }
            if (abs(d[i] - d[i + 1]) > 2 &&
                i != n - 2) {
                f = 0;
                break;
            }
        }
        if (f && cnt1 >= 2) {
            puts("Yes");
        }else {
            puts("No");
        }
    }
}
