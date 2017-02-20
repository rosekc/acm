//2016-10-22-17.48
//UVa232

#include <cstdio>
#include <cstring>
using namespace std;

char board[15][15];
int d[15][15];
int r, c;
bool check(int x, int y)
{
    return (x < 0 || y < 0 || board[x][y] == '*');
}
bool check2(int &x, int &y)
{
    return y < c && board[x][y] != '*';
}
bool check3(int &x, int &y)
{
    return x < r && board[x][y] != '*';
}
int main()
{
    int con1 = 1;
    bool f = 0;
    while (scanf("%d", &r) != EOF && r)
    {
        if (f) puts("");
        f = 1;
        scanf("%d", &c);
        memset(d, 0, sizeof(d));
        for (int i = 0; i < r; i++)
        {
            scanf("%s", &(board[i][0]));
        }
        printf("puzzle #%d:\nAcross\n", con1++);
        int con = 1;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (board[i][j] == '*') continue;
                if (check(i - 1, j) || check(i, j - 1)) d[i][j] = con++;
            }
        }
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (d[i][j])
                {
                    if (j - 1 >= 0 && board[i][j - 1] != '*') continue;
                    int t = j;
                    printf("%3d.%c", d[i][j], board[i][t++]);
                    while (check2(i, t)) printf("%c", board[i][t++]);
                    printf("\n");
                }
            }
        }
        printf("Down\n", c++);
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (d[i][j])
                {
                    if (i - 1 >= 0 && board[i - 1][j] != '*') continue;
                    int t = i;
                    printf("%3d.%c", d[i][j], board[t++][j]);
                    while (check3(t, j)) printf("%c", board[t++][j]);
                    printf("\n");
                }
            }
        }
    }
}
