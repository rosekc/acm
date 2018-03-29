#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
const ll mod = 2147493647;
int t, N, a, b;
ll ans[7] = {2, 1, 16, 8, 4, 2, 1};
struct mat {
    ll a[7][7] = {
        {1, 2, 1, 4, 6, 4, 1},
        {1, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 4, 6, 4, 1},
        {0, 0, 0, 1, 3, 3, 1},
        {0, 0, 0, 0, 1, 2, 1},
        {0, 0, 0, 0, 0, 1, 1},
        {0, 0, 0, 0, 0, 0, 1}
    };;
};
mat mat_mul(mat x, mat y) {
    mat res;
    memset(res.a, 0, sizeof(res.a));
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            for (int k = 0; k < 7; k++) {
                res.a[i][j] += (x.a[i][k] * y.a[k][j]) % mod;
                res.a[i][j] %= mod;
            }
        }
    }
    return res;
}
mat Quick_Matrix(int N) {
    mat res;
    memset(res.a, 0, sizeof(res.a));
    mat c;
    for (int i = 0; i < 7; i++) res.a[i][i] = 1;
    while (N) {
        if (N & 1) res = mat_mul(res, c);
        c = mat_mul(c, c);
        N = N >> 1;
    }
    return res;
}
main() {
    ios::sync_with_stdio(false);
    //cout<<(1<<31)-1<<endl;
    //cout<<mod<<endl;
    cin >> t;
    while (t--) {
        cin >> N >> a >> b;
        if (N == 1) cout << a % mod << endl;
        else if ( N == 2) cout << b % mod << endl;
        else {
            ans[0] = b;
            ans[1] = a;
            ll answ = 0;
            mat mi = Quick_Matrix(N - 2);
            for (int i = 0; i < 7; i++) {
                answ += (mi.a[0][i] * ans[i]) % mod;
                answ %= mod;
            }
            cout << answ << endl;
        }
    }

}
