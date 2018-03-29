//2017-10-29-23.44
//H

#include <bits/stdc++.h>

using namespace std;

const int SIGMA_SIZE = 6;
const int MAXNODE = 11000;
const int MAXS = 150 + 10;

int i_node[MAXNODE];

//map<string,int> ms;
struct AhoCorasickAutomata {
    int ch[MAXNODE][SIGMA_SIZE];
    int f[MAXNODE];    // fail函数
    int val[MAXNODE];  // 每个字符串的结尾结点都有一个非0的val
    int last[MAXNODE]; // 输出链表的下一个结点
    int cnt[MAXS];
    int sz;

    void init() {
        sz = 1;
        memset(ch[0], 0, sizeof(ch[0]));
        memset(cnt, 0, sizeof(cnt));
        memset(i_node, 0, sizeof i_node);
        //ms.clear();
    }

    // 插入字符串。v必须非0
    void insert(int *s, int v, int n) {
        int u = 0;
        for (int i = 0; i < n; i++) {
            int c = s[i];
            if (!ch[u][c]) {
                memset(ch[sz], 0, sizeof(ch[sz]));
                val[sz] = 0;
                ch[u][c] = sz++;
            }
            u = ch[u][c];
        }
        val[u] = v;
        i_node[v] = u;
        //ms[string(s)] = v;
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
                //while (v && !ch[v][c]) v = f[v];
                f[u] = ch[v][c];
                //last[u] = val[f[u]] ? f[u] : last[f[u]];
            }
        }
    }
};

AhoCorasickAutomata ac;
int N;
struct Mat {
    const static int maxn = 110;
    double a[maxn][maxn];
    Mat() {
        memset(a, 0, sizeof a);
    }
};
Mat operator *(const Mat &a, const Mat &b) {
    Mat c;
    for (int k = 0; k <= N; k++) {
        for (int i = 0; i <= N; i++) {
            if (a.a[i][k] > 0) {
                for (int j = 0; j <= N; j++) {
                    c.a[i][j] += a.a[i][k] * b.a[k][j];
                }
            }
        }
    }
    return c;
}
Mat operator ^(Mat a, long long p) {
    Mat c, tmp = a;
    for (int i = 0; i <= N; i++) {
        c.a[i][i] = 1;
    }
    while (p) {
        if (p % 2) c = c * tmp;
        p /= 2;
        tmp = tmp * tmp;
    }
    return c;
}

int s[20];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, l;
        cin >> n >> l;
        ac.init();
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < l; j++) {
                cin >> s[j];
                s[j]--;
            }
            ac.insert(s, i, l);
        }
        ac.getFail();
        N = ac.sz;
        Mat a;
        for (int i = 0; i < ac.sz; i++) {
            if (ac.val[i]) {
                a.a[i][i] += 1;
                continue;
            }
            for (int j = 0; j < 6; j++) {
                a.a[ac.ch[i][j]][i] += 1.0 / 6;
            }
        }
        a = a^(1<<28);
        for (int i = 1; i <= n; i++) {
            if (i != 1) cout << " ";
            cout << setprecision(6) << fixed << a.a[i_node[i]][0];
        }
        cout << endl;
    }
}
