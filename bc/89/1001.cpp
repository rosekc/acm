//2016-10-29-19.02
//Bestcoder 89 1001

#include <cstdio>
#include <cstring>
using namespace std;

char in[10010];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%s", in + 1);
        int con = 0, len = strlen(in + 1);
        for (int i = 1; i <= len; i++)
        {
            for (int p = 2;; p++)
            {
                if (i * p * p > len) break;
                if (in[i] == 'y' && in[i * p] == 'r' && in[i * p * p] == 'x') con++;
                if (in[i] == 'x' && in[i * p] == 'r' && in[i * p * p] == 'y') con++;
            }
        }
        printf("%d\n", con);
    }
}
