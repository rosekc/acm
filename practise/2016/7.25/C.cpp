#include<iostream>
#include<cstdio>
#include<cstring>
#include <queue>

using namespace std;

struct node
{
    int t;
    friend bool operator < (node a, node b)
    {
        return a.t > b.t;
    }
};
priority_queue<node> q;
node d[26];
char str[100001];

int main()
{
    int t, n;
    int re;

    scanf("%d", &t);

    while (t--)
    {
        re = 0;
        scanf("%d%s", &n, str);

        for (int i = 0; i < 26; i++)
        {
            d[i].t = 0;
        }

        for (int i = 0; i < strlen(str); i++)
        {
            //printf("123\n");
            d[int(str[i] - 'a')].t++;
        }
        for (int i = 0; i < 26; i++)
        {
            if(d[i].t != 0) q.push(d[i]);
            //printf("%d\n", i);
        }

        while (1)
        {
            //printf("789\n");
            node sum;
            sum.t = q.top().t;
            q.pop();
            if(q.empty())
            {
                re += sum.t;
                break;
            }
            sum.t += q.top().t;
            re += sum.t;
            q.pop();
            //printf("%d\n", re);
            if(q.empty()) break;
            q.push(sum);
        }
        if(n >= re) printf("yes\n");
        else printf("no\n");
    }
}
