//2017-09-09-13.50
//G

#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define next Next
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
const int maxn = 100000 + 10;
int sum[maxn << 2];
void PushUP(int rt) {
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}
void update(int p, int add, int l, int r, int rt) {
    if (l == r) {
        sum[rt] += add;
        return ;
    }
    int m = (l + r) >> 1;
    if (p <= m) update(p, add, lson);
    else update(p, add, rson);
    PushUP(rt);
}
int query(int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R) {
        return sum[rt];
    }
    int m = (l + r) >> 1;
    int ret = 0;
    if (L <= m) ret += query(L, R, lson);
    if (R > m) ret += query(L, R, rson);
    return ret;
}
void kmp_pre(char x[], int m, int next[]) {
    int i, j;
    j = next[0] = -1;
    i = 0;
    while (i < m) {
        while (-1 != j && x[i] != x[j])j = next[j];
        next[++i] = ++j;
    }
}
/*
* kmpNext[]的意思：next'[i]=next[next[...[next[i]]]] (直到next'[i]<0或者
x[next'[i]]!=x[i])
* 这样的预处理可以快一些
*/
void preKMP(char x[], int m, int kmpNext[]) {
    int i, j;
    j = kmpNext[0] = -1;
    i = 0;
    while (i < m) {
        while (-1 != j && x[i] != x[j])j = kmpNext[j];
        if (x[++i] == x[++j])kmpNext[i] = kmpNext[j];
        else kmpNext[i] = j;
    }
}
/*
* 返回x在y中出现的次数，可以重叠
*/
int next[maxn];
void KMP_Count(char x[], int m, char y[], int n) {
    //x是模式串，y是主串
    int i, j;
    int ans = 0;
    //preKMP(x,m,next);
    kmp_pre(x, m, next);
    i = j = 0;
    while (i < n) {
        while (-1 != j && y[i] != x[j])j = next[j];
        i++;
        j++;
        if (j >= m) {
            update(i - m + 1, 1, 1, n, 1);
            j = next[j];
        }
    }
}
char s[maxn], t[20];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, q;
    cin >> T;
    while (T--) {
        memset(sum, 0, sizeof sum);
        cin >> q >> s >> t;
        int sl = strlen(s);
        int tl = strlen(t);
        KMP_Count(t, tl, s, sl);
        //cout << query(1, 3, 1, sl, 1) << endl;
        while (q--) {
            string c;
            cin >> c;
            if (c[0] == 'Q') {
                int l, r;
                cin >> l >> r;
                if (l > r - tl + 1) {
                    cout << 0 << endl;
                    break;
                }
                cout << query(l, r - tl + 1, 1, sl, 1) << endl;
            }
            if (c[0] == 'C') {
                int p;
                cin >> p >> c;
                p--;
                for (int i = p - tl + 1; i <= p; i++) {
                    if (i + tl > sl) continue;
                    bool ok1 = 1, ok2 = 1;
                    for (int j = 0; j < tl; j++) {
                        if (i + j == p) {
                            if (c[0] != t[j]) {
                                ok2 = 0;
                            }
                            if (s[p] != t[j]) {
                                ok1 = 0;
                            }
                            continue;
                        }
                        if (s[i + j] != t[j]) {
                            //cout <<i + j << endl;
                            //cout << s[i+j] << " " << t[j] << endl;
                            ok1 = 0;
                            ok2 = 0;
                        }
                    }
                    //cout << i + 1 << endl;
                    //cout << ok1 << " " << ok2 << endl;
                    if (ok1 != ok2) {
                        //cout << i + 1 << " " << ok2 << endl;
                        update(i + 1, ok2 ? 1 : -1, 1, sl, 1);
                    }
                }
                s[p] = c[0];
            }
        }
    }
}
