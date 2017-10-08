//2017-10-06-21.41
//A

#include <bits/stdc++.h>
using namespace std;

const int maxn = 2010;
int a[maxn], b[maxn];

int main() {
    int n;
    cin >> n;
    set<int> s;
    for (int i = 0; i < n; i++) cin >> a[i], s.insert(a[i]);
    for (int j = 0; j < n; j++) cin >> b[j], s.insert(b[j]);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            //cout << (a[i] ^ b[j]) << endl;
            if (s.count(a[i] ^ b[j])) cnt++;
        }
    }
    //cout << cnt << endl;
    if (cnt % 2 == 0) puts("Karen");
    else puts("Koyomi");
}
