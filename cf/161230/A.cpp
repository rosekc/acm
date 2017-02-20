//2016-12-30-22.28
//A

#include <cstdio>
using namespace std;

int main()
{
    int n, k;
    while (scanf("%d%d", &n, &k) != EOF)
    {
        int t = 60 * 4 - k;
        int tt = 5, con = 0;
        while (1)
        {
            if (con == n) break;
            t -= tt;
            if (t >= 0) con++;
            else break;
            tt += 5;
        }
        printf("%d\n", con);
    }
}
