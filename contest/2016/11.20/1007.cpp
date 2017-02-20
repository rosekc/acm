//2016-11-20-12.44
//1007

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

struct Node
{
    int x, y;
    bool operator < (const Node &b)
    {
        if (b.x == x) return y > b.y;
        else return x < b.x;
    }
};
Node d[100000 + 10];
int main()
{
    int n, x, y;
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d", &x, &y);
            d[i] = {x, 1};
            d[n + i] = {y, -1};
        }
        sort(d, d + 2 * n);
        int m = 0;

        int sum = 0;
        for (int i = 0;; i++)
        {
            sum += d[i].y;
            if (i < 2 * n)
            {
                if (d[i].x == d[i + 1].x) continue;
            }
            else
            {
                if (m < sum) m = sum;
                break;
            }
            if (m < sum) m = sum;
        }

        printf("%d\n", m - 1);
    }
}
