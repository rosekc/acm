#include <cstdio>
#include <set>
#include <cstring>
#include <cmath>
using namespace std;
char a[100];
char b[100];
set<int> s;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        s.clear();
        scanf("%s%s", a, b);
        int sla = strlen(a);
        int slb = strlen(b);
        for (int i = 0; i < sla; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                if (a[i] - '0' == j)
                {
                    continue;
                }
                int t = 0;
                for (int k = 0; k < sla; k++)
                {
                    if (i == k)
                    {
                        t += j * pow(2, sla - k - 1);
                    }
                    else
                        t += (a[k] - '0') * pow(2, sla - k - 1);
                }
                s.insert(t);
                //printf("%d\n", t);
            }
        }
        //puts("");
        for (int i = 0; i < slb; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (b[i] - '0' == j)
                {
                    continue;
                }
                int t = 0;
                for (int k = 0; k < slb; k++)
                {
                    if (i == k)
                    {
                        t += j * pow(3, slb - k - 1);
                    }
                    else
                        t += (b[k] - '0') * pow(3, slb - k - 1);
                }
                //printf("%d\n", t);
                if (s.find(t) != s.end())
                {
                    printf("%d\n", t);
                    break;
                }
            }
        }
    }
}
