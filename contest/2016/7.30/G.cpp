#include <cstdio>

using namespace std;

struct data
{
    int num;
    int con = 0;
    int b;
};

struct node
{
    int t;
    friend bool operator < (node a, node b)
    {
        return a.t > b.t;
    }
};
priority_queue<node> q;
node d[27];

bool cmp(data a, data b)
{
    return a.con > b.con;
}
int c[27];

int main()
{
    char str[50];
    while (scanf("%s", str) && strcmp(str, "END") != 0)
    {
        int con = 0;
        for(int i = 0; i < 27; i++)
        {
            c[i].num = i;
        }
        for (int i = 0; i < strlen(str); i++)
        {
            int tmp = str[i] - 'A';
            if(tmp < 0) tmp = 26;
            if(c[tmp] == 0) con++;
            c[tmp]++;
        }
        int a = con * 16;

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


        printf("%d", a, b)
    }
}
