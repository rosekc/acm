//2017-02-18-17.09
//A

#include <bits/stdc++.h>

using namespace std;

bool d[100000 + 10];

int main()
{
    int n;
    scanf("%d", &n);
    int cur = n, t;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &t);
        d[t] = 1;
        if (t == cur)
        {
            for (int j = t;; j--)
            {
                if (!d[j]) {cur = j; break;}
                printf("%d ", j);
            }
        }
        puts("");
    }
}
