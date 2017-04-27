//2017-04-23-14.39
//H

#include <bits/stdc++.h>

using namespace std;

int g[30][30];
int T, n, m, a, b, u, v;


int main()
{

    cin >> T;
    while (T--) {
        cin >> n >> m >> a >> b;
        memset(g, 0, sizeof g);
        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            g[u][v] = g[v][u] = 1;
        }
        if (g[a][b]) puts("chhappy");
        else puts("chsad");
    }
}
