//2017-05-13-14.04
//Uva 1625

#include <bits/stdc++.h>

using namespace std;

const int maxn = 5000 + 100;
int d[2][maxn], c[2][maxn];
int sp1[26], ep1[26], sp2[26], ep2[26];
char s1[maxn], s2[maxn];
const int INF = 1e9;
int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> (s1 + 1) >> (s2 + 1);
        int n = strlen(s1 + 1);
        int m = strlen(s2 + 1);
        for (int i = 1; i <= n; i++) s1[i] -= 'A';
        for (int i = 1; i <= m; i++) s2[i] -= 'A';
        for (int i = 0; i < 26; i++) {
            sp1[i] = sp2[i] = INF;
            ep1[i] = ep2[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            sp1[s1[i]] = min(sp1[s1[i]], i);
            ep1[s1[i]] = i;
        }
        for (int i = 1; i <= m; i++) {
            sp2[s2[i]] = min(sp2[s2[i]], i);
            ep2[s2[i]] = i;
        }
        memset(d, 0, sizeof d);
        memset(c, 0, sizeof c);
        int t = 0;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (!i && !j) {
                    continue;
                }
                int v1 = INF, v2 = INF;
                if (i) v1 = d[t ^ 1][j] + c[t ^ 1][j];
                if (j) v2 = d[t][j - 1] + c[t][j - 1];
                d[t][j] = min(v1, v2);
                if (i) {
                    c[t][j] = c[t ^ 1][j];
                    if (sp1[s1[i]] == i && sp2[s1[i]] > j) c[t][j]++;
                    if (ep1[s1[i]] == i && ep2[s1[i]] <= j) c[t][j]--;
                }else if (j) {
                    c[t][j] = c[t][j - 1];
                    //cout << sp1[s2[j]] << endl;
                    if (sp2[s2[j]] == j && sp1[s2[j]] > i) c[t][j]++;
                    if (ep2[s2[j]] == j && ep1[s2[j]] <= i) c[t][j]--;
                }
                //cout << c[i][j] << " ";
            }
            t ^= 1;
            //cout << endl;
        }
        cout << d[t ^ 1][m] << endl;
    }
}
