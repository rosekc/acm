//2017-11-01-21.53
//LA4670

#include <bits/stdc++.h>

using namespace std;

const int SIGMA_SIZE = 26;
const int MAXNODE = 11000;
const int MAXS = 150 + 10;
struct AhoCorasickAutomata {
    int ch[MAXNODE][SIGMA_SIZE];
    int f[MAXNODE];     // fail函数
    int val[MAXNODE];   // 每个字符串的结尾结点都有一个非0的val
    int last[MAXNODE];  // 输出链表的下一个结点
    int cnt[MAXS];
    int sz;

    void init() {
        sz = 1;
        memset(ch[0], 0, sizeof(ch[0]));
        memset(cnt, 0, sizeof(cnt));
    }

    // 字符c的编号
    int idx(char c) {
        return c - 'a';
    }

    // 插入字符串。v必须非0
    void insert(string s, int v) {
        int u = 0, n = s.length();
        for (int i = 0; i < n; i++) {
            int c = idx(s[i]);
            if (!ch[u][c]) {
                memset(ch[sz], 0, sizeof(ch[sz]));
                val[sz] = 0;
                ch[u][c] = sz++;
            }
            u = ch[u][c];
        }
        val[u] = v;
    }


    // 在T中找模板
    int find(string T) {
        int n = T.length();
        int j = 0;  // 当前结点编号，初始为根结点
        for (int i = 0; i < n; i++) {  // 文本串当前指针
            int c = idx(T[i]);
            //while (j && !ch[j][c]) j = f[j];  // 顺着细边走，直到可以匹配
            j = ch[j][c];
            if (val[j]) {
                cnt[val[j]]++;
            }
            int t = j;
            while (last[t]) {
                t = last[t];
                cnt[val[t]]++;
            }
        }
    }

    // 计算fail函数
    void getFail() {
        queue<int> q;
        f[0] = 0;
        // 初始化队列
        for (int c = 0; c < SIGMA_SIZE; c++) {
            int u = ch[0][c];
            if (u) {
                f[u] = 0;
                q.push(u);
                last[u] = 0;
            }
        }
        // 按BFS顺序计算fail
        while (!q.empty()) {
            int r = q.front();
            q.pop();
            for (int c = 0; c < SIGMA_SIZE; c++) {
                int u = ch[r][c];
                if (!u) {
                    ch[r][c] = ch[f[r]][c];
                    continue;
                }
                q.push(u);
                int v = f[r];
                while (v && !ch[v][c]) v = f[v];
                f[u] = ch[v][c];
                last[u] = val[f[u]] ? f[u] : last[f[u]];
            }
        }
    }
};
AhoCorasickAutomata ac;
string s[160];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while (cin >> n && n) {
        for (int i = 1; i <= n; i++) {
            cin >> s[i];
        }
        ac.init();
        //sort(s, s + n);
        //n = unique(s, s + n) - s;
        for (int i = 1; i <= n; i++) {
            ac.insert(s[i], i);
            //cout << s[i] << endl;
        }
        ac.getFail();
        string tt;
        cin >> tt;
        ac.find(tt);
        int ans = -1;
        for (int i = 1; i <= n; i++) {
            ans = max(ans, ac.cnt[i]);
            //cout << ac.cnt[i] << endl;
        }
        cout << ans << endl;
        for (int i = 1; i <= n; i++) {
            if (ac.cnt[i] == ans) cout << s[i] << endl;
        }
    }
}
