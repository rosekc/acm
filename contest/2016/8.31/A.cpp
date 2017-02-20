#include <cstdio>
#include <algorithm>
using namespace std;
int d[1005];
int main()
{
    int n, l;
    while (scanf("%d%d", &n, &l) != EOF)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &d[i]);
        }
        sort(d, d + n);
        double ret = d[0];
        for (int i = 1; i < n; i++)
        {
            ret = max(ret, (d[i] - d[i - 1]) / 2.0);
        }
        ret = max(ret, double(l - d[n - 1]));
        printf("%.10f\n", ret);
    }
}
