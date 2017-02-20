//2017-02-02-21.35
//

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, z, con = 0;
    scanf("%d%d%d", &n, &m, &z);
    for (int i = 1; i <= z; i++)
    {
        if (i % n == 0 && i % m == 0) con++;
    }
    printf("%d\n", con);
}
