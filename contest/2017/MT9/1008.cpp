//2017-08-23-14.32
//1008

#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5;
long long a[maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m;
    while (cin >> m) {
        for (int i = 0; i < m; i++) {
            cin >> a[i];
        }
        sort(a, a + m);
        vector<long long> ans;
        priority_queue<long long, vector<long long>, greater<long long>> q;
        for (int i = 0; i < m; i++) {
            while (i < m && !q.empty() && q.top() == a[i]) {
                q.pop();
                i++;
            }
            if (i >= m) break;
            for (auto j : ans) {
                q.push(a[i] + j);
            }
            ans.push_back(a[i]);
        }
        cout << ans.size() << endl;
        bool first = 1;
        for (auto i : ans) {
            if (!first) {
                cout << ' ';
            }
            cout << i;
            first = 0;
        }
        cout << endl;
    }
}
