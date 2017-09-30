//2017-09-25-18.31
//A

#include <bits/stdc++.h>

using namespace std;

int a[101];

int main() {
    int n;
    int t;
    set<int> s;
    cin >> n;
    while (n--) {
        cin >> t;
        s.insert(t);
        a[t]++;
    }
    int p = -1;
    if (s.size() == 2) {
        for (int i : s) {
            if (p == -1) {
                p = a[i];
            }else if (p != a[i]){
                puts("NO");
                return 0;
            }
        }
        puts("YES");
        for (int i : s) {
            cout << i << " ";
        }
        cout << endl;
    }else puts("NO");
}
