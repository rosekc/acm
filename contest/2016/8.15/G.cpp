#include <cstdio>
#include <algorithm>
using namespace std;
struct data
{
    int val;
    int lim;
};

data d[100 + 10];
bool cmp(const data &a, const data &b)
{
    return a.val < b.val;
}
int main()
{
    int k, e, n;

    while (scanf("%d%d%d", &k, &e, &n) != EOF)
    {
        int ret = 0;
        for (int i = 0; i < n; i++)
        {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            d[i] = {e - a + c, b};
        }
        sort(d, d + n, cmp);
        int ind = 0;
        while (1)
        {
            if (d[ind].lim < k)
            {
                k -= d[ind].lim;
                ret += d[ind].val * d[ind++].lim;
            }
            else
            {
                ret += d[ind].val * k;
                break;
            }
        }
        printf("%d\n", ret);
    }
}
