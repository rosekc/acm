//2016-09-12-23.14
//Uva 11988
//Á´±í

#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 100000 + 10;
int r, ind, next[maxn];
char in[maxn];
int main()
{
    while (scanf("%s", in + 1) != EOF)
    {
        next[0] = 0;
        ind = r = 0;
        int len = strlen(in + 1);
        for (int i = 1; i <= len; i++)
        {
            if (in[i] == '[')
            {
                ind = 0;
            }
            else if (in[i] == ']')
            {
                ind = r;
            }
            else
            {
                next[i] = next[ind];
                next[ind] = i;
                if (ind == r) r = i;
                ind = i;
            }
            //printf("%d\n", ind);
        }
        for (int i = next[0]; i != 0; i = next[i])
        {
            printf("%c", in[i]);
        }
        printf("\n");
    }
}
