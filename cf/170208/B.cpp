//2017-02-08-15.04
//B

#include <bits/stdc++.h>
using namespace std;

int d[100000 + 10];
int n;
bool check(int &a, int &b, int &c)
{
    //printf("%d %d %d\n", a, b, c);
    return a + b > c &&
           a + c > b &&
           b + c > a;
}
bool solve()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (check(d[i], d[j], d[k])) return 1;
                else break;
            }
        }
    }
    return 0;
}


int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &d[i]);
    }
    sort(d, d + n);
    if (solve()) puts("YES");
    else puts("NO");
}
