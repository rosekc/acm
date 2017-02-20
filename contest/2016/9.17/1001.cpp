//2016-09-17-12.25
//qingdao inter 1001

#include <cstdio>
#include <cmath>
#include <set>
using namespace std;
set<int> s;
int main()
{
    for (int i = 0; i <= 30; i++)
        for (int j = 0; j <= 19; j++)
            for (int k = 0; k <= 13; k++)
                for (int l = 0; l <= 11; l++)
    {
        int n = pow(2, i) * pow(3, j) * pow(5, k) * pow(7, l);
        if (n >= 1000000000 + 10) continue;
        else s.insert(n);
    }
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        printf("%d\n", *s.lower_bound(n));
    }
}
