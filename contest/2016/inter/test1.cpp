#include <iostream>
#include <queue>
using namespace std;
struct Node
{
    int x;
    int y;
    int remtime;
    int step;
} begin;
int map[8][8];
int mark[8][8];
int dir[4][2]={0,1,1,0,0,-1,-1,0};
int m, n;

void bfs()
{
    queue <Node> q;
    q.push(begin);
    mark[begin.x][begin.y] = begin.remtime;
    Node p, tmp;
    while(!q.empty())
    {
        p = q.front();
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            tmp = p;
            tmp.x += dir[i][0];
            tmp.y += dir[i][1];
            if(tmp.x >= n || tmp.x < 0 || tmp.y >= m || tmp.y < 0 || map[tmp.x][tmp.y] == 0)
                continue;
            tmp.step ++;
            tmp.remtime --;
            if(map[tmp.x][tmp.y] == 3)
            {
                cout << tmp.step << endl;
                return;
            }
            else if(map[tmp.x][tmp.y] == 4)
                tmp.remtime = 6;
            if(tmp.remtime > 1 && tmp.remtime > mark[tmp.x][tmp.y])
            {
                mark[tmp.x][tmp.y] = tmp.remtime;
                q.push(tmp);
            }
        }
    }
    cout << "-1" << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
            {
                cin >> map[i][j];
                if(map[i][j] == 2)
                {
                    begin.x = i;
                    begin.y = j;
                    begin.remtime = 6;
                    begin.step = 0;
                }
                mark[i][j] = 0;
            }
        bfs();
    }
    return 0;
}
