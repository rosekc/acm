//2017-04-23-13.13
//G

#include <bits/stdc++.h>

using namespace std;

int sum[100100];

int main()
{
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        int cur;
        sum[0] = 0;
        int re = -0x3fffffff;
        int bestj = 0x3fffffff, besto = 0;
        for (int i = 1; i <= n; i++) {
            cin >> cur;
            sum[i] = sum[i - 1] + cur;
            //cout << sum[i] << endl;
            if (i % 2 == 0) {
                re = max(re, sum[i] - bestj);
                besto = min(besto, sum[i]);
            }else {
                re = max(re, sum[i] - besto);
                //puts("233");
                bestj = min(bestj, sum[i]);
            }
        }
        cout << re << endl;
    }
}
