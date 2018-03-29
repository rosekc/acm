//2017-10-23-18.12
//Uva 12003
// 分块
// 给出数组A[1,2,...,n]和m条指令，
// 每条指令形如(L,R,v,p)表示统计出A[L]...A[R]中严格小于v的有多少个，
// 然后把A[p]修改成uk/(R-L+1)
#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e5 + 10;
const int SIZE = sqrt(maxn);

int a[maxn], b[maxn / SIZE + 10][SIZE];
int n, m, u;
int get_k(int i, int v) {
    return lower_bound(b[i], b[i] + SIZE, v) - b[i];
}

void query(int l, int r, int v, int p) {
    int L = l / SIZE, R = r / SIZE, k = 0;
    if (L == R) {
        for (int i = l; i <= r; i++) {
            if (a[i] < v) k++;
        }
    }else {
        for (int i = l; i < L * SIZE + SIZE; i++) {
            if (a[i] < v) k++;
        }
        for (int i = R * SIZE; i <= r; i++) {
            if (a[i] < v) k++;
        }
        for (int i = L + 1; i < R; i++) {
            k += get_k(i, v);
        }
    }
    //cout << k << endl;
    int pb = p / SIZE;
    int cp = (long long)u * k / (r - l + 1);
    *lower_bound(b[pb], b[pb] + SIZE, a[p]) = cp;
    a[p] = cp;
    sort(b[pb], b[pb] + SIZE);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n >> m >> u) {
        int p = 0, c = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            b[p][c++] = a[i];
            if (c == SIZE) {
                sort(b[p], b[p] + SIZE);
                p++;
                c = 0;
            }
        }
        if (c) sort(b[p], b[p] + c);
        while (m--) {
            int l, r, v, p;
            cin >> l >> r >> v >> p;
            l--, r--, p--;
            query(l, r, v, p);
        }
        for (int i = 0; i < n; i++) {
            cout << a[i] << endl;
        }
    }
}
