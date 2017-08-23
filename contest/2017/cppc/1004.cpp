//2017-08-19-12.46
//

#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int maxn = 1e6 + 10;
char s1[maxn], s2[maxn];

#define next Next
int next[maxn];

void kmp_pre(const char x[], int m, int next[]) {
    int i, j;
    j = next[0] = -1;
    i = 0;
    while (i < m) {
        while (-1 != j && x[i] != x[j])j = next[j];
        next[++i] = ++j;
    }
}

long long KMP_Count(const char x[], long long m, const char y[], long long n) {
    //x是模式串，y是主串
    long long i, j;
    long long ans = 0;
    kmp_pre(x, m, next);
    i = j = 0;
    while (i < n) {
        while (-1 != j && y[i] != x[j]) {
            j = next[j];
            ans += (j + 1) * j / 2;
            ans %= mod;
        }
        i++;
        j++;
        ans += j;
        ans %= mod;
        if (j >= m) {
            j = next[j];
            ans += (j + 1) * j / 2;
            ans %= mod;
        }
    }
    while (j >= 0) {
        j = next[j];
        ans += (j + 1) * j / 2;
        ans %= mod;
    }
    return ans;
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%s%s", s1, s2);
        int l1 = strlen(s1);
        int l2 = strlen(s2);
        reverse(s1, s1 + l1);
        reverse(s2, s2 + l2);
        cout << KMP_Count(s2, l2, s1, l1) << endl;
    }
}
