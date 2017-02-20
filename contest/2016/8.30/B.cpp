#include <cstdio>
#include <cstring>
using namespace std;

int d[1005];
int re[1005];
int f(int n)
{
    if (d[n] != -1) return d[n];
    if (n < 100)
    {
        //printf("%d %d\n", f(n / 10) , f(n % 10));
        return d[n] = f(n - n % 10) + f(n % 10);
    }
    else
    {
        if (n % 100 == 0)
        {
            d[n] = f(n / 100) + 7;
        }
        else
        {
            d[n] = f(n / 100) + 10 + f(n % 100);
        }
        return d[n];
    }
}
int getre(int n)
{
    if (re[n] != -1) return re[n];
    else return getre(n - 1) + f(n);
}
int main()
{
    memset(d, -1, sizeof(d));
    memset(re, -1, sizeof(re));
    re[1] = 3;
    d[0] = 0;
    d[1] = 3;
    d[2] = 3;
    d[3] = 5;
    d[4] = 4;
    d[5] = 4;
    d[6] = 3;
    d[7] = 5;
    d[8] = 5;
    d[9] = 4;
    d[10] = 3;
    d[11] = 6;
    d[12] = 6;
    d[13] = 8;
    d[14] = 8;
    d[15] = 7;
    d[16] = 7;
    d[17] = 9;
    d[18] = 8;
    d[19] = 8;
    d[20] = 6;
    d[30] = 6;
    d[40] = 5;
    d[50] = 5;
    d[60] = 5;
    d[70] = 7;
    d[80] = 6;
    d[90] = 6;
    d[1000] = 11;
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int in;
        scanf("%d", &in);
        printf("%d\n", getre(in));
    }
}
