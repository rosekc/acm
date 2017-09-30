//2017-09-17-12.55
//1003

#include <bits/stdc++.h>

using namespace std;

struct Trie {
    int next[100010][26], fail[100010], end[100010];
    int root, L;
    int newnode() {
        for (int i = 0; i < 26; i++)
            next[L][i] = -1;
        end[L++] = 0;
        return L - 1;
    }
    void init() {
        L = 0;
        root = newnode();
    }
    void insert(string &buf) {
        int len = buf.length();
        int now = root;
        for (int i = 0; i < len; i++) {
            if (next[now][buf[i] - 'a'] == -1)
                next[now][buf[i] - 'a'] = newnode();
            now = next[now][buf[i] - 'a'];
        }
        end[now]++;
    }
    void build() {
        queue<int>Q;
        fail[root] = root;
        for (int i = 0; i < 26; i++)
            if (next[root][i] == -1)
                next[root][i] = root;
            else {
                fail[next[root][i]] = root;
                Q.push(next[root][i]);
            }
        while ( !Q.empty() ) {
            int now = Q.front();
            Q.pop();
            for (int i = 0; i < 26; i++)
                if (next[now][i] == -1)
                    next[now][i] = next[fail[now]][i];
                else {
                    fail[next[now][i]] = next[fail[now]][i];
                    Q.push(next[now][i]);
                }
        }
    }
    int query(string &buf) {
        int len = buf.length();
        int now = root;
        int res = 0;
        for (int i = 0; i < len; i++) {
            now = next[now][buf[i] - 'a'];
            int temp = now;
            while ( temp != root ) {
                res += end[temp];
                end[temp] = 0;
                temp = fail[temp];
            }
        }
        return res;
    }
    void debug() {
        for (int i = 0; i < L; i++) {
            printf("id = %3d,fail = %3d,end = %3d,chi = [", i, fail[i], end[i]);
            for (int j = 0; j < 26; j++)
                printf("%2d", next[i][j]);
            printf("]\n");
        }
    }
};
Trie ac;
string buf[100000 + 10];
int a[100000 + 10];
int cmp(int a, int b) {
    return buf[a].length() < buf[b].length();
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
#define endl '\n'
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        ac.init();
        int mxl = 0, p = -1;
        for (int i = 0; i < n; i++) {
            cin >> buf[i];
            ac.insert(buf[i]);
            if (mxl < buf[i].length()) {
                mxl = buf[i].length();
                p = i;
            }
        }
        ac.build();
        if (ac.query(buf[p]) == n) {
            cout << buf[p] << endl;
        } else cout << "No" << endl;
    }
}
