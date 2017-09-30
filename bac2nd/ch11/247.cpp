//2017-09-08-11.54
//Uva 247

#include <bits/stdc++.h>

using namespace std;

unordered_map<string, int> dict;
string na[30];
bool G[30][30];
int fa[30];
int getfa(int x) {
    return fa[x] == x ? x : fa[x] = getfa(fa[x]);
}

int main() {
    int n, m, kase = 1;
    while (cin >> n >> m && n) {
        int cnt = 0;
        dict.clear();
        memset(G, 0, sizeof (G));
        iota(fa, fa + n, 0);
        for (int i = 0; i < n; i++) G[i][i] = 1;
        while (m--) {
            string a, b;
            cin >> a >> b;
            if (dict.count(a) == 0) {
                na[cnt] = a;
                dict[a] = cnt++;
            }
            if (dict.count(b) == 0) {
                na[cnt] = b;
                dict[b] = cnt++;
            }
            G[dict[a]][dict[b]] = 1;
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    G[i][j] = G[i][j] || (G[i][k] && G[k][j]);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (G[i][j] && G[j][i]) {
                    int x = getfa(i);
                    int y = getfa(j);
                    if (x != y) {
                        fa[x] = y;
                    }
                }
            }
        }
        vector<int> ans[n];
        for (int i = 0; i < n; i++) {
            ans[getfa(i)].push_back(i);
        }
        if (kase != 1) cout << endl;
        cout << "Calling circles for data set " << kase++ <<  ":\n";
        for (int i = 0; i < n; i++) {
            bool first = 1;
            for (int j : ans[i]) {
                if (!first) cout << ", ";
                cout << na[j];
                first = 0;
            }
            if (!first) cout << '\n';
        }
    }
}
