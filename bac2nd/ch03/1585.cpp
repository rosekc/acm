//2016-09-28-22.58
//UVa 1585

#include <cstdio>
#include <cstring>
using namespace std;

char in[85];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%s", in);
        int ret = 0, p = 1;
        int len = strlen(in);
        for (int i = 0; i < len; i++)
        {
            if (in[i] == 'X') p = 1;
            else ret += p++;
        }
        printf("%d\n", ret);
    }
}
