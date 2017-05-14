//2017-05-03-15.09
//Eigth

#include <bits/stdc++.h>

using namespace std;

int mr[] = { -1, 0, 1, 0};
int mc[] = {0, 1, 0, -1};

struct St {
    int d[9];
    bool operator == (const St &b) const {
        return equal(d, d + 9, b.d);
    }
};

namespace std {
    template<>
    struct hash<St> {
        size_t operator() (const St& p)const {
            size_t seed = 0;
            for_each(p.d, p.d + 9, [&seed](int t) {
                seed = (seed << 3) ^ (hash<int> {}(t));
            });
            //cout << '\n' << seed << endl;
            return seed;
        }
    };
}

unordered_map<St, string> m;
queue<St> que;

char dir[] = {'d', 'l', 'u', 'r'};

void bfs(St st) {
    int xpos = -1;
    int ypos = -1;
    for (int i = 0; i < 9; i++)
        if (st.d[i] == 0) {
            xpos = i / 3;
            ypos = i % 3;
        }
    for (int i = 0; i < 4; i++) {
        int tx = xpos + mr[i];
        int ty = ypos + mc[i];
        if (tx >= 0 && tx < 3
                && ty >= 0 && ty < 3) {
            St next;
            memcpy(next.d, st.d, sizeof next.d);
            int t = next.d[3 * tx + ty];
            next.d[3 * tx + ty] = next.d[3 * xpos + ypos];
            next.d[3 * xpos + ypos] = t;
            if (!m.count(next)) {
                m[next] = dir[i] + m[st];
                que.push(next);
            }
        }
    }
}

int readline(char *in) {
    int read = getchar();
    char* p;
    while (read != '\n' && read != '\c' && read != EOF) {
        *p++ = read;
        read = getchar();
    }
    return read;
}

int main() {
    St st;
    iota(st.d, st.d + 8, 1);
    st.d[8] = 0;
    m[st] = "";
    que.push(st);
    while (!que.empty()) {
        bfs(que.front());
        que.pop();
    }
    St find;
    char in[40];
    while (gets(in) != NULL) {
        char *p = strchr(in, 'x');
        if (!p) return 0;
        *p = '0';
        char *token = strtok(in, " ");
        generate_n(find.d, 9, [&token]()->int{
            int t;
            if (token == NULL) return 0;
            sscanf(token, "%d", &t);
            token = strtok(NULL, " ");
            return t;
        });
        if (m.count(find) == 1) {
            cout << m[find] << endl;;
        } else puts("unsolvable");
    }
}
