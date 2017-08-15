#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
const int mod = 1e9 + 7;
const int MAXN = 1e5 + 10;
struct Node {
    int id;
    long long zm[MAXN];
} Num[26 + 1];
int maxp[MAXN];
int vis[30];
int b[30];
long long fuzhi[30];
void add(int z, int wi) {
    maxp[z] = max(wi, maxp[z]);
    if (++Num[z].zm[wi] == 26) {
        add(z, wi + 1);
        Num[z].zm[wi] = 0;
    }
}

bool cmp(int a, int b) {
    Node &A = Num[a]; Node &B = Num[b];
    if (maxp[a] != maxp[b]) return maxp[a] < maxp[b];
    for (int i = maxp[a]; i > 0; i--) {
        if (A.zm[i] != B.zm[i]) {
            return A.zm[i] < B.zm[i];
        }
    }
    return A.zm[0] < B.zm[0];
}

int main() {
    //ios::sync_with_stdio(false);
    int t = 0;
    int n;
    char str[MAXN];
    for (int i = 0; i < 26; i++) b[i] = i;
    while (~scanf("%d", &n)) {
        memset(fuzhi, 0, sizeof(fuzhi));
        memset(vis, 0, sizeof(vis));
        memset(maxp, -1, sizeof maxp);
        for (int i = 0; i < 26; i++) {
            Num[i].id = i;
            memset(Num[i].zm, 0, sizeof(Num[i].zm));
        }
        while (n--) {
            scanf("%s", str);
            int len = strlen(str);
            if (len > 1)
                vis[str[0] - 'a'] = 1;

            for (int i = 0; i < len; i++) {
                add(str[i] - 'a', len - i - 1);
            }
        }

        sort(b, b + 26, cmp);
        /*for(int i=0;i<26;i++) cout<<w[i].id<<' ';
        cout<<endl;*/
        int fi = 0;
        while (vis[b[fi]] != 0) fi++;
        fuzhi[b[fi]] = 1;
        //cout<<fi<<endl;
        int ii = 2;
        while (ii <= 26) {
            for (int j = 0; j < 26; j++) {
                if (!fuzhi[b[j]]) {
                    fuzhi[b[j]] = ii;
                    ii++;
                }
            }
        }
        /*for(int i=0;i<26;i++) cout<<fuzhi[i]<<' ';
        cout<<endl;*/
        long long sum = 0;
        for (int i = 0; i < 26; i++) {
            long long tem = 0;
            long long mul = fuzhi[Num[i].id] - 1;
            for (int j = maxp[i]; j >= 0; j--) {
                tem *= 26;
                tem %= mod;
                if (Num[i].zm[j] != 0)
                    tem += (mul * Num[i].zm[j]) % mod;;
            }
            sum += tem;
            sum %= mod;
        }
        printf("Case #%d: %lld\n", ++t, sum);
    }
    return 0;
}
