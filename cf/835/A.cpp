//2017-07-31-22.35
//A

#include <bits/stdc++.h>

using namespace std;

int main() {
    int s, v1, v2, t1, t2;
    cin >> s >> v1 >> v2 >> t1 >> t2;
    int tt1 = s * v1 + 2 * t1;
    int tt2 = s * v2 + 2 * t2;
    if (tt1 < tt2) puts("First");
    else if (tt1 > tt2) puts("Second");
    else puts("Friendship");
}
