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

#define eps 1e-9
const int MAXN = 505;
double a[MAXN][MAXN], x[MAXN]; //方程的左边的矩阵和等式右边的值，求解之后x存的就是结果
int equ, var; //方程数和未知数个数
/*
*返回0表示无解，1表示有解
*/
int Gauss() {
    int i, j, k, col, max_r;
    for (k = 0, col = 0; k < equ && col < var; k++, col++) {
        max_r = k;
        for (i = k + 1; i < equ; i++)
            if (fabs(a[i][col]) > fabs(a[max_r][col]))
                max_r = i;
        if (fabs(a[max_r][col]) < eps)return 0;
        if (k != max_r) {
            for (j = col; j < var; j++)
                swap(a[k][j], a[max_r][j]);
            swap(x[k], x[max_r]);
        }
        x[k] /= a[k][col];
        for (j = col + 1; j < var; j++)a[k][j] /= a[k][col];
        a[k][col] = 1;
        for (i = 0; i < equ; i++)
            if (i != k) {
                x[i] -= x[k] * a[i][k];
                for (j = col + 1; j < var; j++)a[i][j] -= a[k][j] * a[i][col];
                a[i][col] = 0;
            }
    }
    return 1;
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
        equ = var = ac.sz;
        memset(a, 0, sizeof a);
        memset(x, 0, sizeof x);
        for (int i = 0; i < ac.sz; i++) {
            a[i][i] = -1;
        }
        x[0] = -1;
        for (int i = 0; i < ac.sz; i++) {
            if (!ac.val[i]) {
                for (int j = 0; j < 6; j++) {
                    //cout << ac.ch[i][j] << endl;
                    a[ac.ch[i][j]][i] += 1.0 / 6;
                }
            }
        }
        //cout << "123";
//        for (int i = 0; i < ac.sz; i++) {
//            for (int j = 0; j < ac.sz; j++) {
//                cout << a[i][j] << " ";
//            }
//            cout << endl;
//        }
        Gauss();
        for (int i = 1; i <= n; i++) {
            if (i != 1) cout << " ";
            cout << setprecision(6) << fixed << x[i_node[i]];
        }
        cout << endl;
    }
}
