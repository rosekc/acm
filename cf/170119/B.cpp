//2017-01-19-23.21
//B

#include <cstdio>
#include <cstring>
using namespace std;

char d[108];
int re[4];
int re1[4];
int main()
{
    while (scanf("%s", d) != EOF)
    {
        int len = strlen(d);
        for (int i = 0; i < len; i += 4)
        {
            for (int j = 0; j < 4; j++)
            {
                if (d[i + j] == '!') re[j]++;
                else if (d[i + j] == 'R')
                {
                    re1[0] = j;
                }
                else if (d[i + j] == 'B')
                {
                    re1[1] = j;
                }
                else if (d[i + j] == 'Y')
                {
                    re1[2] = j;
                }
                else if (d[i + j] == 'G')
                {
                    re1[3] = j;
                }
            }
        }
        printf("%d %d %d %d\n", re[re1[0]], re[re1[1]], re[re1[2]], re[re1[3]]);
    }
}
