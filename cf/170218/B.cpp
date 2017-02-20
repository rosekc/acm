//2017-02-18-17.19
//B

#include <bits/stdc++.h>

using namespace std;
long long st, ed, sp, d[100000 + 10];
int n;
int main()
{
    scanf("%lld%lld%lld%d", &st, &ed, &sp, &n);
    if (n == 0) {printf("%lld\n", st); return 0;}
    long long nextt = st, re, mint = 10e12 + 9;
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &d[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (nextt - ed >= ed) break;
        if (d[i] > nextt)
        {
            re = nextt;
            mint = 0;
            break;
        }
        else
        {
            long long t = nextt - (d[i] - 1);
            if (mint > t && ed - d[i] + 1 >= sp) mint = t, re = d[i] - 1;
            //printf("%lld %lld\n",re, t);
            nextt += sp;
            while (d[i] == d[i + 1]) nextt += sp, i++;
            //printf("nt:%lld\n", nextt);
        }
    }
    if (nextt + sp <= ed)
    {
        re = nextt;
        //puts("1");
    }
    printf("%lld\n", re);
}
