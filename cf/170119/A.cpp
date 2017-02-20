//2017-01-19-23.09
//A

#include <cstdio>
#include <algorithm>
using namespace std;
int d[101];
int main()
{
    int n, mx = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &d[i]);
        mx = max(mx, d[i]);
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += (mx - d[i]);
    }
    printf("%d\n", sum);
}
