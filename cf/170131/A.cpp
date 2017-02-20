//2017-01-31-22.41
//

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    if (a == 0 && b == 0)
    {
        puts("NO");
        return 0;
    }
    if (a < b) swap(a, b);
    if (a - b == 0 || a - b == 1) puts("YES");
    else puts("NO");
}
