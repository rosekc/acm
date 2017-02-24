//2017-02-23-22.56
//B

#include <bits/stdc++.h>

using namespace std;

int d[100000 + 100];
int maxn = 100000 + 100;
int main()
{
    for (int i = 2; i < maxn; i++)
    {
        if (d[i] != 0) continue;
        d[i] = 1;
        for (int j = 2; j * i < maxn; j++)
        {
            d[i * j] = 2;
        }
    }
    int in;
    scanf("%d", &in);
    printf("%d\n", in == 1 || in == 2 ? 1 : 2);
    for (int i = 2; i < in + 2; i++)
    {
        printf("%d ", d[i]);
    }
}
