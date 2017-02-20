//2016-12-24-12.43
//A

#include <cstdio>
using namespace std;
const int maxn = 100000 + 10;
long long d1[maxn], d2[maxn];
int n;
void op(int i)
{
    if (n - 1 != i)
    {
        d1[i - 1] += d1[i];
        d1[i + 1] += d1[i];
        d1[i] = -d1[i];
    }
    else
    {
        d1[i - 1] += d1[i];
        d1[i] = -d1[i];
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {

        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%lld", &d1[i]);
        }
        for (int i = 0; i < n; i++)
        {
            scanf("%lld", &d2[i]);
        }
        if (n == 1)
        {
            if (d1[0] == d2[0]) puts("Yes");
            else puts("No");
            continue;
        }
        int st = 1, ed = n - 1, state = 1, ischange = 0;
        while (1)
        {
            if (st > ed)
            {
                if (d1[st - 1] == d2[st - 1] && d1[ed] == d2[ed]) puts("Yes");
                else puts("No");
                break;
            }
            if (state)
            {
                //puts("a");
                if (d1[st - 1] != d2[st - 1])
                {
                    op(st);
                    if (d1[st - 1] != d2[st - 1])
                    {
                        if (ischange)
                        {
                            puts("No");
                            break;
                        }
                        op(st);
                        ischange = 1;
                        state = 0;
                        continue;
                    }
                }
                ischange = 0;
                st++;
            }
            else
            {
                //puts("b");
                if (ed == n - 1)
                {
                    //puts("c");
                    if (d1[ed] != d2[ed])
                    {
                        op(ed);
                        //printf("%d %d\n", d1[ed], d2[ed]);
                        if (d1[ed] != d2[ed])
                        {
                            op(ed - 1);
                            //printf("%d %d\n", d1[ed], d2[ed]);
                            //puts("d");
                            if (d1[ed] != d2[ed])
                            {
                                op(ed);
                                if (d1[ed] != d2[ed])
                                {
                                    op(ed - 1);
                                    if (ischange)
                                    {
                                        puts("No");
                                        break;
                                    }
                                    ischange = 1;
                                    state = 1;
                                    continue;
                                }
                            }
                        }
                    }
                    ed--;
                    ischange = 0;
                }
                else if (d1[ed + 1] != d2[ed + 1])
                {
                    op(ed);
                    if (d1[ed + 1] != d2[ed + 1])
                    {
                        if (ischange)
                        {
                            puts("No");
                            break;
                        }
                        op(ed);
                        ischange = 1;
                        state = 1;
                        continue;
                    }
                }
                ed--;
                ischange = 0;
            }
        }
    }
}
