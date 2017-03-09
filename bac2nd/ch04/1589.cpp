//2017-02-18-14.16
//Uva 1589

#include <bits/stdc++.h>

using namespace std;

struct node
{
    int x, y;
    char type[5];
};

int bx, by, n;
node d[8];

const int mr[] = {-1, 0, 1, 0};
const int mc[] = {0, 1, 0, -1};

bool checkpoint(int x, int y)
{
    for (int j = 0; j < n; j++)
    {
        if (x == d[j].x && y == d[j].y)
        {
            return 0;
        }
    }
    return 1;
}

int findjmppiece(int x1, int y1, int x2, int y2)
{
    int con = 0;
    if (x1 == x2)
    {
        for (int j = 0; j < n; j++)
        {
            if (d[j].x == x1 && d[j].y > min(y1, y2) &&
                    d[j].y < max(y1, y2))
            {
                con++;
            }
        }
    }
    else if (y1 == y2)
    {
        for (int j = 0; j < n; j++)
        {
            if (d[j].y == y1 && d[j].x > min(x1, x2) &&
                    d[j].x < max(x1, x2))
            {
                con++;
            }
        }
    }
    else return -1;
    //printf("%d\n", con);
    return con;
}
const int mr1[] = {-1, 1, 1, -1};
const int mr2[] = {-1, -1, 1, 1};
const int mc1[] = {1, 1, -1, -1};
const int mc2[] = {-1, 1, 1, -1};
bool checkhorse(int x1, int y1, int x2, int y2)
{
    for (int i = 0; i < 4; i++)
    {
        int tx = mr[i] + x1;
        int ty = mc[i] + y1;
        if (!checkpoint(tx, ty)) continue;
        if ((x2 == tx + mr1[i] && y2 == ty + mc1[i]) ||
            (x2 == tx + mr2[i] && y2 == ty + mc2[i])) return 1;
    }
    return 0;
}
bool check()
{

    for (int i = 0; i < 4; i++)
    {
        int tx = bx + mr[i];
        int ty = by + mc[i];
        if (ty >= 4 && ty <= 6 &&
                tx >= 1 && tx <= 3)
        {
            //printf("%d %d\n", tx, ty);
            bool f = 0;
            for (int j = 0; j < n; j++)
            {
                if (d[j].x == tx && d[j].y == ty) continue;
                if (d[j].type[0] == 'R' || d[j].type[0] == 'G')
                {
                    if (findjmppiece(tx, ty, d[j].x, d[j].y) == 0)
                    {
                        //puts("111");
                        f = 1;
                        break;
                    }
                }
                if (d[j].type[0] == 'C')
                {
                    if (findjmppiece(tx, ty, d[j].x, d[j].y) == 1)
                    {
                        //puts("222");
                        f = 1;
                        break;
                    }
                }
                if (d[j].type[0] == 'H')
                {
                    if (checkhorse(d[j].x, d[j].y, tx, ty))
                    {
                        //puts("333");
                        f = 1;
                        break;
                    }
                }
            }
            if (!f) return 0;
        }
    }
    return 1;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    while (scanf("%d%d%d", &n, &bx, &by) != EOF && n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%s%d%d", d[i].type, &d[i].x, &d[i].y);
        }
        if (check()) puts("YES");
        else puts("NO");
    }
}
