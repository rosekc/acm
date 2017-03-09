//2017-02-11-22.45
//Uva 133

#include <bits/stdc++.h>
using namespace std;

const int maxn = 25;
int n, k, m, a[maxn];

void go(int &p, int d, int t)
{
    while (t--)
    {
        //puts("1");
        do {p = (p + d + n - 1) % n + 1;}
        while (a[p] == 0);
    }
}

int main()
{
    while (scanf("%d%d%d", &n, &k, &m) != EOF && n)
    {
        for (int i = 1; i <= n; i++) a[i] = i;
        int left = n;
        int p1 = n, p2 = 1;
        while (left)
        {
            go(p1, 1, k);
            go(p2, -1, m);
            printf("%3d", p1); left--;
            if (p2 != p1) { printf("%3d", p2); left--;}
            a[p1] = a[p2] = 0;
            if (left) printf(",");
        }
        puts("");
    }
}
