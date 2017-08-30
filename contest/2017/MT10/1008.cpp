//2017-08-24-16.08
//1008

#include <bits/stdc++.h>
using namespace std;

namespace IO {
    const int MX = 4e7;
    char buf[MX]; int c, sz;
    void begin() {
        c = 0;
        sz = fread(buf, 1, MX, stdin);
    }
    inline bool read(int &t) {
        while(c < sz && buf[c] != '-' && (buf[c] < '0' || buf[c] > '9')) c++;
        if(c >= sz) return false;
        bool flag = 0; if(buf[c] == '-') flag = 1, c++;
        for(t = 0; c < sz && '0' <= buf[c] && buf[c] <= '9'; c++) t = t * 10 + buf[c] - '0';
        if(flag) t = -t;
        return true;
    }
}


const int maxn = 1e5 + 10;
vector<int> G[maxn];
int vis[maxn];
int ans, k, n;
void dfs(int c) {
    for (int i : G[c]) {
        //cout << i << ' ' << k << endl;
        dfs(i);
        if (!vis[c] && !vis[i]) {
            vis[c] = vis[i] = 1;
            ans++;
            k -= 2;
        }
    }
}

int main() {
    IO::begin();
    int T;
    IO::read(T);
    while (T--) {
        IO::read(n), IO::read(k);
        memset(vis, 0, sizeof vis);
        for (int i = 1; i <= n; i++) G[i].clear();
        ans = 0;
        for (int i = 2, j; i <= n; i++) {
            IO::read(j);
            G[j].push_back(i);
        }
        dfs(1);
        //cout << k << endl;
        cout << ans + k << endl;
    }
}
