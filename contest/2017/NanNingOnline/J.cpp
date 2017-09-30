//2017-09-24-13.36
//J

#include <bits/stdc++.h>

using namespace std;

map<string, int> dist;
string node[1000000];
int cnt = 0;
int getid(string &s) {
    if (dist.count(s)) {
        return dist[s];
    }
    node[cnt] = s;
    dist[s] = cnt;
    return cnt++;
}
bool vis[1000000];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < 5; i++) {
        string a, b;
        cin >> a >> b;
        memset(vis, 0, sizeof vis);
        cnt = 0;
        dist.clear();
        queue<pair<int, int> > q;
        q.push({getid(a), 0});
        vis[getid(a)] = 1;
        int bid = getid(b);
        while (!q.empty()) {
            auto s = q.front();
            q.pop();
            //cout << node[s.first] << " " << s.second << endl;
            for (int i = 1; i < n; i++) {
                string ss(node[s.first]);
                swap(ss[0], ss[i]);
                int id = getid(ss);
                if (id == bid) {
                    cout << s.second + 1 << endl;
                    goto ex;
                }
                //cout << ss << "id " << getid(ss) << " " << id << endl;
                //cout << vis[4] <<endl;
                if (!vis[id]) {
                    //cout << ss << "id " << getid(ss) << endl;
                    q.push({id, s.second + 1});
                    vis[id] = 1;
                }
            }
        }
ex:
        ;
    }
}
