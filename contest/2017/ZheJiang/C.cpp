//2017-04-22-14.00
//C

#include <bits/stdc++.h>

using namespace std;

string dc[205];

int T, n, q, c;

struct Trie {
    int next[50000][2], end[50000];
    int root, L;
    int newnode() {
        for (int i = 0; i < 2; i++)
            next[L][i] = -1;
        end[L++] = -1;
        return L - 1;
    }
    void init() {
        L = 0;
        root = newnode();
    }
    void insert(int buf[], int id) {
        int len = q;
        int now = root;
        for (int i = 0; i < len; i++) {
            if (next[now][buf[i]] == -1)
                next[now][buf[i]] = newnode();
            now = next[now][buf[i]];
        }
        if (end[now] == -1) end[now] = id;
        else end[now] = -2;
    }
    int query(int buf[]) {
        int len = q;
        int now = root;
        for (int i = 0; i < len; i++) {
            if (next[now][buf[i]] == -1)
                return -1;
            now = next[now][buf[i]];
        }
        return end[now];
    }
};

int qu[205][25];
int inqu[25];
map<string, int> id;
int main() {
    cin >> T;
    while (T--) {
        cin >> n >> q >> c;
        id.clear();
        for (int i = 0; i < c; i++) {
            cin >> dc[i];
            id[dc[i]] = i;
        }
        int cnt;
        string in;
        memset(qu, 0, sizeof qu);
        for (int i = 0; i < q; i++) {
            cin >> cnt;
            for (int j = 0; j < cnt; j++) {
                cin >> in;
                qu[id[in]][i] = 1;
            }
        }
        Trie t;
        t.init();
        for (int i = 0; i < c; i++) {
            t.insert(qu[i], i);
            //for (int j = 0; j < q; j++) {
            //    cout << qu[i][j] << " ";
            //}
            //puts("");
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < q; j++) cin >> inqu[j];
            int ans = t.query(inqu);
            if (ans < 0) {
                puts("Let's go to the library!!");
            } else cout << dc[ans] << endl;;
        }
    }
}
