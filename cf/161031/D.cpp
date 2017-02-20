//2017-01-19-21.06
//D

#include <cstdio>
#include <algorithm>
using namespace std;
struct Stone
{
    long long a, b, c;
    int pos;
    bool operator < (const Stone &s)const
    {
        if (c == s.c)
        {
            if (b == s.b)
            {
                return a > s.a;
            }
            return b < s.b;
        }
        return c < s.c;
    }
};
Stone d[100000 + 20];
Stone getd()
{
    long long a, b, c;
    scanf("%lld%lld%lld", &a, &b, &c);
    if (a > b) swap(a, b);
    if (a > c) swap(a, c);
    if (b > c) swap(b, c);
    return {a, b, c};
}
int trycom(int i, int j)
{
    if (d[i].b == d[j].b && d[i].c == d[j].c)
    {
        return min(d[i].a + d[j].a, min(d[i].b, d[i].c));
    }
    return -1;
}

int main()
{
    int n, ans1, ans2 = -1;;
    long long re = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        d[i] = getd();
        d[i].pos = i;
        if (re < d[i].a) re = d[i].a, ans1 = i;
    }
    sort(d, d + n);
    for (int i = 0; i < n; i++)
    {
        int t = trycom(i, i + 1);
        if (re < t)
        {
            re = t;
            ans1 = d[i].pos, ans2 = d[i + 1].pos;
        }
    }
    if (ans2 == -1) printf("1\n%d\n", ans1 + 1);
    else printf("2\n%d %d\n", ans1 + 1, ans2 + 1);
}
