//2016-12-10-10.56
//C

#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int d[1000000 + 10];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &d[i]);
        }
        d[n] = -1;
        sort(d, d + n);
        int con = 1;
        for (int i = 0; i < n; i++)
        {
            if (d[i] == d[i + 1])
            {
                con++;
            }
            else
            {
                if (con % 2 == 1)
                {
                    printf("%d\n", d[i]);
                    break;
                }
                con = 1;
            }
        }
    }
}
