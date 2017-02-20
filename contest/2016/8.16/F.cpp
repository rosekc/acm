#include <cstdio>

struct point
{
    int x;
    int y;
};

const int maxn = 100 + 5;
point d[maxn];

int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d", &d[i].x, &d[i].y);
        }
        for (int i = 0; i < m; i++)
        {
            int x, y;
            int c1 = 0;
            scanf("%d%d", &x, &y);
            for (int j = 0; j < n; j++)
            {
                if ((d[j].x > x && d[j].y > y) ||
                    (d[j].x < x && d[j].y < y))
                {
                    c1++;
                }
            }
            printf("%d", 2 * c1 - n);
            if (i != m - 1) printf("\n");
        }
    }
}
