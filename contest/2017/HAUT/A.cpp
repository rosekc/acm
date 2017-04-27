//2017-04-23-12.01
//A

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1110;

struct Node {
    string name;
    int cnt, id;
    int ac[15];
    int t;
    Node(){}
    Node(string _name, int _id) {
        id = _id;
        cnt = 0;
        t = 0;
        name = _name;
        memset(ac, 0, sizeof ac);
    }
    bool operator < (const Node& b) const {
        if (cnt == b.cnt) {
            if (t == b.t) {
                return id < b.id;
            }
            return t < b.t;
        }
        return cnt > b.cnt;
    }
};

Node d[maxn];

int main()
{
    int n, m, k;
    while (cin >> n >> m >> k) {
        string t;
        for (int i = 1; i <= n; i++) {
            cin >> t;
            d[i] = Node(t, i);
        }
        int tt, id, pid;
        string re;
        for (int i = 0; i < m; i++) {
            cin >> tt >> id >> pid >> re;
            if (d[id].ac[pid] == 1) continue;
            if (re[0] == 'W') {
                d[id].ac[pid]--;
            }else {
                d[id].t += (tt - d[id].ac[pid] * 20);
                d[id].cnt++;
                d[id].ac[pid] = 1;
            }
        }
        sort(d + 1, d + n + 1);
        for (int i = 1; i <= n; i++) {
            cout << d[i].name << " " << d[i].cnt << " " << d[i].t << endl;
        }
    }
}
