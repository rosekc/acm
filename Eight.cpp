#include <cstdio>
#include <cstring>
#include <set>
#include <string>
using namespace std;
typedef int State[9];
const int maxstate = 362880 + 1000;
State st[maxstate], goal;
string res[maxstate];
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
int vis[362880], fact[9];
void init_lookup_table( )
{
    memset(res, 0, sizeof(res));
    fact[0] = 1;
    for (int i = 1; i < 9; i++) fact[i] = fact[i - 1] * i;
}
int try_to_insert(int s)
{
    int code = 0;
    for (int i = 0; i < 9; i++)
    {
        int cnt = 0;
        for (int j = i + 1; j < 9; j++) if (st[s][j] < st[s][i]) cnt++;
        code += fact[8 - i] * cnt;
    }
    if (vis[code]) return 0;
    return vis[code] = 1;
}

int bfs()
{
    init_lookup_table();
    int front = 1, rear = 2;
    while (front < rear)
    {
        State& s = st[front];
        if (memcmp(goal, s, sizeof(s)) == 0) return front;
        int z;
        for (z = 0; z < 9; z++) if (!s[z]) break;
        int x = z / 3, y = z % 3;
        for (int d = 0; d < 4; d++)
        {
            int newx = x + dx[d];
            int newy = y + dy[d];
            int newz = newx * 3 + newy;
            if (newx >= 0 && newx < 3 && newy >= 0 && newy < 3)
            {
                State& t = st[rear];
                memcpy(&t, &s, sizeof(s));
                t[newz] = s[z];
                t[z] = s[newz];
                res[rear] = res[front] + char(d + '0');
                if (try_to_insert(rear)) rear++;
            }
        }
        front++;
    }
    return 0;
}

int main()
{
    goal[0] = 1;
    goal[1] = 2;
    goal[2] = 3;
    goal[3] = 4;
    goal[4] = 5;
    goal[5] = 6;
    goal[6] = 7;
    goal[7] = 8;
    goal[8] = 0;

    char s[30];
    while (gets(s) != NULL)
    {
        int ind = 0;
        int i = 0;
        while (s[ind] != '\0')
        {
            if (s[ind] == ' ')
            {
                ind++;
                continue;
            }
            if (s[ind] == 'x')
            {
                st[1][i++] = 0;
            }
            else
            {
                st[1][i++] = (s[ind] - '0');
            }
            ind++;
        }
        int ans = bfs();
        if (ans > 0)
        {
            for (int i = 0; i < res[ans].size(); i++)
            {
                switch (res[ans][i])
                {
                case '0':
                    printf("u");
                    break;
                case '1':
                    printf("d");
                    break;
                case '2':
                    printf("l");
                    break;
                case '3':
                    printf("r");
                    break;
                }
            }
            printf("\n");
        }
        else printf("unsolvable\n");
    }
}
