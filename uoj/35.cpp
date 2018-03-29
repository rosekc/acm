//2017-11-12-22.35
//UOJ35

#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 100;

struct SuffixArray {
    char s[maxn];      // 原始字符数组（最后一个字符应必须是0，而前面的字符必须非0）
    int sa[maxn];     // 后缀数组
    int rk[maxn];   // 名次数组. rank[0]一定是n-1，即最后一个字符
    int height[maxn]; // height数组
    int t[maxn], t2[maxn], c[maxn]; // 辅助数组
    int n; // 字符个数

    // m为最大字符值加1。调用之前需设置好s和n
    void build_sa(int m) {
        int i, *x = t, *y = t2;
        for (i = 0; i < m; i++) c[i] = 0;
        //来一次基数排序
        for (i = 0; i < n; i++) c[x[i] = s[i]]++;
        //这里取每个字母在SA数组中最大编号。显然某个字母的最大编号是比它小的前缀和
        for (i = 1; i < m; i++) c[i] += c[i - 1];
        //逆序搞编号，保证权相同情况下编号小的在前面
        for (i = n - 1; i >= 0; i--) sa[--c[x[i]]] = i;
        for (int k = 1; k <= n; k <<= 1) {
            int p = 0;
            // y[i] 用来表示 第二关键字的SA
            // 下面先排第二关键字为0的位置
            for (i = n - 1; i >= n - k; i--) y[p++] = i;
            // 错位刚好把第一关键字的SA获得第二关键字的SA
            for (i = 0; i < n; i++) if (sa[i] >= k) y[p++] = sa[i] - k;
            //再次基数排序
            for (i = 0; i < m; i++) c[i] = 0;
            for (i = 0; i < n; i++) c[x[y[i]]]++;
            for (i = 0; i < m; i++) c[i] += c[i - 1];
            for (i = n - 1; i >= 0; i--) sa[--c[x[y[i]]]] = y[i];
            swap(x, y);
            p = 1;
            x[sa[0]] = 0;
            for (i = 1; i < n; i++)
                if (y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + k] == y[sa[i] + k])
                    x[sa[i]] = p - 1;
                else x[sa[i]] = p++;
            if (p >= n) break;
            m = p;
        }
    }

    void build_height() {
        int i, j, k = 0;
        for (i = 0; i < n; i++) rk[sa[i]] = i;
        for (i = 0; i < n; i++) {
            if (rk[i] == 0) {
                height[0] = 0;    // 第一个后缀的 LCP 为 0。
                continue;
            }
            if (k) k--;
            j = sa[rk[i] - 1];
            //cout << j << endl;
            while (s[i + k] == s[j + k] && i + k < n && j + k < n) k++;
            height[rk[i]] = k;
        }
    }
};

SuffixArray sa;

int main() {
    scanf("%s", sa.s);
    sa.n = strlen(sa.s);
    sa.build_sa(128);
    for (int i = 0; i < sa.n; i++) {
        printf("%d ", sa.sa[i] + 1);
    }
    puts("");
    if (sa.n == 1) return 0;
    sa.build_height();
    for (int i = 1; i < sa.n; i++) {
        printf("%d ", sa.height[i]);
    }
    puts("");
}
