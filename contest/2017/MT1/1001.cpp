//2017-07-25-12.06
//1001

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> ans;
    double t = 1;
    ans.push_back(0);
    for (int i = 1; i < 10e5 + 10; i++) {
        t *= 2;
        if (t >= 10) {
            t /= 10;
            ans.push_back(i - 1);
        }
    }
    int n, kase = 1;
    while (cin >> n) {
        printf("Case #%d: %d\n", kase++, lower_bound(ans.begin(), ans.end(), n) - ans.begin() - 1);
    }
}
