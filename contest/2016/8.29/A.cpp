#include <cstdio>
#include <algorithm>>
using namespace std;
int g[105][105];

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                scanf("%d", &g[i][j]);
            }
        }
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = 0; j <= i; j++)
            {
                g[i][j] = max(g[i + 1][j], g[i + 1][j + 1]) + g[i][j];
            }
        }
        printf("%d\n", g[0][0]);
    }
}
