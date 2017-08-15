//2017-07-31-22.44
//B

#include <bits/stdc++.h>

using namespace std;

int a[10];

int main() {
    int k;
    string s;
    cin >> k >> s;
    for (int i = 0; i < s.length(); i++) {
        a[s[i] - '0']++;
    }
    int sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += (a[i] * i);
    }
    int cnt = 0;
    for (int i = 0; i < 9; i++) {
        if (a[i] == 0) continue;
        if (sum >= k) break;
        int t = k - sum;
        //cout << (((t-1) / (9 - i)) + 1) << " " << a[i] << endl;
        //cout << ((((t-1) / (9 - i)) + 1) <= a[i]) << endl;
        if ((((t-1) / (9 - i)) + 1) <= a[i]) {
            //puts("233215615");
            cnt += (((t-1) / (9 - i)) + 1);
            //cout << cnt <<endl;
            break;
        }
        sum += (9 - i) * a[i];
        cnt += a[i];
    }
    cout << cnt << endl;
}
