//2017-07-19-13.22
//1625

#include <bits/stdc++.h>

using namespace std;

const int maxn = 5050, INF = 1e9;
char s1[maxn], s2[maxn];
int d[2][maxn], c[2][maxn], sp1[maxn], sp2[maxn], ep1[maxn], ep2[maxn];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> (s1 + 1) >> (s2 + 1);
        int l1 = strlen(s1 + 1);
        int l2 = strlen(s2 + 1);
        for (int i = 1; i <= l1; i++) s1[i] -= 'A';
        for (int i = 1; i <= l2; i++) s2[i] -= 'A';
        for (int i = 0; i < 26; i++) {
            sp1[i] = sp2[i] = INF;
            ep1[i] = ep2[i] = 0;
        }
        for (int i = 1; i <= l1; i++) {
            sp1[s1[i]] = min(sp1[s1[i]], i);
            ep1[s1[i]] = i;
        }
        for (int i = 1; i <= l2; i++) {
            sp2[s2[i]] = min(sp2[s2[i]], i);
            ep2[s2[i]] = i;
        }
        memset(c, 0, sizeof c);
        memset(d, 0, sizeof d);
        int t = 0;
        for (int i = 0; i <= l1; i++) {
            for (int j = 0; j <= l2; j++) {
                if (!i && !j) continue;
                int v1 = i ? d[t ^ 1][j] + c[t ^ 1][j] : INF;
                int v2 = j ? d[t][j - 1] + c[t][j - 1] : INF;
                d[t][j] = min(v1, v2);
                if (i) {
                    c[t][j] = c[t ^ 1][j];
                    if (sp1[s1[i]] == i && sp2[s1[i]] > j) c[t][j]++;
                    if (ep1[s1[i]] == i && ep2[s1[i]] <= j) c[t][j]--;
                }else if (j) {
                    c[t][j] = c[t][j - 1];
                    if (sp2[s2[j]] == j && sp1[s2[j]] > i) c[t][j]++;
                    if (ep2[s2[j]] == j && ep1[s2[j]] <= i) c[t][j]--;
                }
            }
            t ^= 1;
        }
        cout << d[t ^ 1][l2] << endl;
    }
}
