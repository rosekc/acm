#include <bits/stdc++.h>

using namespace std;

const int maxn = 150;
string s1, s2;
int f[10];
int cost[666666 + 100];
int p[] = {1, 10, 100, 1000, 10000, 100000, 1000000};
//0-5
int idx(int st, int i) {
    return st / p[i] % 10;
}
int change(int &st, int i, int to) {
    st = st - (st / p[i] % 10) * p[i] + to * p[i];
}
void bfs() {
    memset(cost, -1, sizeof cost);
    int st = 654321;
    queue<int> que;
    que.push(st);
    cost[st] = 0;
    while (!que.empty()) {
        int c = que.front();
        que.pop();
        int p = cost[c];
        for (int i = 1; i <= 6; i++) {
            for (int j = 1; j <= 6; j++) {
                int t = c;
                for (int k = 0; k < 6; k++) {
                    if (idx(t, k) == i) change(t, k, j);
                }
                //cout << c << " " << t << " "<< i << " " << j <<  endl;
                if (cost[t] == -1) {
                    //cout << t << endl;
                    cost[t] = p + 1;
                    que.push(t);
                }
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    bfs();
    while (cin >> s1 >> s2) {
        int ans = 999999;
        for (int i = 0; i < s1.length(); i++) {
            s1[i] -= '0';
            s2[i] -= '0';
        }
        if (s1 == s2) {
            cout << "0" << endl;
            continue;
        }
        int ret = 99999999;
        int pp;
        int tt;
        for (int sta = 111111; sta <= 666666; sta++) {
            int ans = cost[sta];
            if (ans == -1) continue;
            for (int i = 0; i < s1.length(); i++) {
                if (idx(sta, s2[i] - 1) != s1[i]) ans++;
            }
            if (ret > ans) {
                tt = sta;
                pp = cost[sta];
                ret = ans;
            }
        }
        //cout << tt << endl;
        //cout << pp << endl;
        cout << ret << endl;
    }
}