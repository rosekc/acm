//2017-09-06-22.36
//D

#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 10;
struct E [
    int v, d, c;
]
vector<E> G[maxn];

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int u, v, d, c;
        cin >> d >> u >> v >> c;
        G[u].push_back({v, d, c});
    }
}
