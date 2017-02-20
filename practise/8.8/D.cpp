#include <cstdio>

const int maxn = 100 + 10;
int arr[maxn][maxn];
int mr[4] = {-1, 0, 1, 0};
int mc[4] = {0, 1, 0, -1};
int h[maxn][maxn];
int r, c;

int f(int i, int j)
{
    if (arr[i][j]) return arr[i][j];
    int ans = 0;
    for (int p = 0; p < 4; p++)
    {
        int tr = i + mr[p];
        int tc = j + mc[p];
        if (tr >= 0 && tr < r && tc >= 0 && tc < c
         && h[tr][tc] > h[i][j])
        {
            int tf = f(tr, tc);
            if (ans < tf) ans = tf;
        }
    }
    arr[i][j] = ans + 1;
    return arr[i][j];
}

int main()
{
    while (scanf("%d%d", &r, &c) != EOF)
    {
        int ret = 0;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                scanf("%d", &h[i][j]);
                arr[i][j] = 0;
            }
        }
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                int tmp = f(i, j);
                if(ret < tmp) ret = tmp;
            }
        }
        printf("%d\n", ret);
    }
}
