//2016-10-18-22.42
//UVa455

#include <cstdio>
#include <cstring>
using namespace std;
char in[90];
int main()
{
    int t, re;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%s", in);
        re = 1;
        int ind = 0;
        int len = strlen(in);
        if (len == 1)
        {
            puts("1");
            goto end;
        }
        for (int i = 1;; i++)
        {
            if (in[ind] == in[i])
            {
                if (ind == re - 1) ind = 0;
                else ind++;
            }
            else
            {
                ind = 0;
                i = re++;
            }
            if (i == len - 1 || re >= len)
            {
                if (ind != 0)
                {
                    ind = 0;
                    i = re++;
                    if (i == len - 1) {re = len; break;}
                    continue;
                }
                break;
            }
        }
        printf("%d\n", re);
        end:
            if (t) printf("\n");
    }
}
