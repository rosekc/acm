//2017-07-27-23.00
//1002

#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
const int maxn = 1e5 + 10;
int a[26][maxn];
int b[26], maxp[26], ans[26];
bool head[26];

string s;

void add(int i, int j) {
    maxp[i] = max(j, maxp[i]);
    if (++a[i][j] == 26) {
        add(i, j + 1);
        a[i][j] = 0;
    }
}

long long cal(int i) {
    long long sum = 0;
    for (int p = maxp[i]; p >= 0; p--) {
        sum = (sum * 26) % mod;
        sum = (sum + (1ll * a[i][p] * ans[i]) % mod) % mod;
    }
    return sum;
}

bool cmp(const int &x, const int &y) {
    if (maxp[x] != maxp[y]) return maxp[x] < maxp[y];
    for (int i = maxp[x]; i > 0; i--) {
        if (a[x][i] != a[y][i]) return a[x][i] < a[y][i];
    }
    return a[x][0] < a[y][0];
}

int main() {
    int n, kase = 1;
    iota(b, b + 26, 0);
    while (cin >> n) {
        memset(a, 0, sizeof a);
        memset(head, 0, sizeof head);
        memset(maxp, -1, sizeof maxp);
        memset(ans, -1, sizeof ans);
        while (n--) {
            cin >> s;
            if (s.length() > 1) {
                head[s[0] - 'a'] = 1;
            }
            for (int i = 0, j = s.length() - 1; i < s.length(); i++, j--) {
                add(s[i] - 'a', j);
            }
        }
        sort(b, b + 26, cmp);
        //cout << cnt << endl;
        for (int i = 0; i < 26; i++) {
            if (!head[b[i]]) {
                ans[b[i]] = 0;
                break;
            }
        }
        for (int i = 0, cur = 1; i < 26; i++) {
            if (ans[b[i]] == -1) {
                ans[b[i]] = cur++;
            }
        }
        //        for (int i = 0; i < 26; i++) {
        //            cout << ans[i] << " ";
        //        }
        //        cout << endl;
        long long sum = 0;
        for (int i = 0; i < 26; i++) {
            sum = (sum + cal(i)) % mod;
        }
        printf("Case #%d: %lld\n", kase++, sum);
    }
}
