//2017-02-21-23.42
//Uva 220

#include <bits/stdc++.h>

using namespace std;
char b[9][9];
char turn;
int mr[] = { -1, -1, 0, 1, 1, 1, 0, -1};
int mc[] = {0, 1, 1, 1, 0, -1, -1, -1};
bool findre[8];
char readchar()
{
    char ch = getchar();
    while (ch == '\n' || ch == '\r') ch = getchar();
    return ch;
}
bool check(int x, int y)
{
    //printf("check:%d %d\n", x, y);
    if (b[x][y] != '-') return 0;
    bool f = 0;
    for (int i = 0; i < 8; i++)
    {
        bool isfirst = 1;
        int tx = x;
        int ty = y;
        for (;;)
        {
            tx += mr[i];
            ty += mc[i];
            if (tx < 1 || tx > 8 || ty < 1 || ty > 8 || b[tx][ty] == '-') break;
            //printf("%d %d %c\n", tx, ty, b[tx][ty]);
            if (!isfirst && turn == b[tx][ty])
            {
                f = 1;
                findre[i] = 1;
            }
            if (isfirst)
            {
                if (turn == b[tx][ty]) break;
                isfirst = 0;
            }
        }
    }
    return f;
}
void L()
{
    bool f = 0, isfirst = 1;
    for (int i = 1; i <= 8; i++)
    {
        for (int j = 1; j <= 8; j++)
        {
            if (check(i, j))
            {
                if (isfirst) isfirst = 0;
                else printf(" ");
                f = 1, printf("(%d,%d)", i, j);
            }
        }
    }
    if (!f) printf("No legal move.");
    puts("");
}
void M()
{
    memset(findre, 0, sizeof findre);
    int x = readchar() - '0', y = readchar() - '0';
    if (!check(x, y)) turn = (turn == 'W' ? 'B' : 'W'), check(x, y);
    b[x][y] = turn;
    for (int i = 0; i < 8; i++)
    {
        int tx = x;
        int ty = y;
        if (findre[i]) for (;;)
            {
                tx += mr[i];
                ty += mc[i];
                if (tx < 1 || tx > 8 || ty < 1 || ty > 8 || b[tx][ty] == turn) break;
                b[tx][ty] = turn;
            }
    }
    int bc = 0, wc = 0;
    for (int i = 1; i <= 8; i++)
    {
        for (int j = 1; j <= 8; j++)
        {
            if (b[i][j] == 'B') bc++;
            if (b[i][j] == 'W') wc++;
        }
    }
    printf("Black - %2d White - %2d\n", bc, wc);
    turn = (turn == 'W' ? 'B' : 'W');
}
int main()
{
    int kase;
    scanf("%d", &kase);
    bool isfirst = 1;
    while (kase--)
    {
        if (isfirst) isfirst = 0;
        else puts("");
        char in;
        for (int i = 1; i <= 8; i++)
            for (int j = 1; j <= 8; j++)
            {
                b[i][j] = readchar();
            }
        turn = readchar();
        for (;;)
        {
            in = readchar();
            switch (in)
            {
            case 'L':
                L();
                break;
            case 'M':
                M();
                break;
            case 'Q':
                goto ex;
                break;
            }
        }
ex:
        for (int i = 1; i <= 8; i++)
        {
            for (int j = 1; j <= 8; j++)
            {
                putchar(b[i][j]);
            }
            puts("");
        }
    }
}
