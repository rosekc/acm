//2017-01-21-19.04
//1001

#include <bits/stdc++.h>
using namespace std;

struct node
{
    int v, c;
    bool operator < (const node &b)const
    {
        return v < b.v;
    }
};
node d[100 + 10];
vector<int> re;
long long getre()
{
    vector<int>::reverse_iterator it;
    int i = 1;
    long long ans = 0;
    for (it = re.rbegin(); it != re.rend(); it++)
    {
        //puts("b");
        ans += i++ * *it;
    }
    return ans;
}
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
            scanf("%d%d", &d[i].v, &d[i].c);
        }
        sort(d, d + n);
        long long ans = 0;
        re.clear();
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j < d[i].c; j++)
            {
                re.push_back(d[i].v);
                long long t = getre();
                //printf("  %d\n", t);
                if (t > ans) ans = t;
                else goto exit;
            }
        }
exit:
        printf("%I64d\n", ans);
    }
}
