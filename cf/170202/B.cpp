//2017-02-02-21.49
//B

#include <bits/stdc++.h>
using namespace std;

int d[200000 + 100];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &d[i]);
    for (int i = 0; i < n / 2; i++)
    {
        if (i % 2 == 0) swap(d[i], d[n - i - 1]);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", d[i]);
    }
    puts("");
}
