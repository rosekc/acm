//2016-10-22-20.13
//UVa1368

#include <cstdio>
#include <cstring>
using namespace std;
char in[55][1005];
int d[4];
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int m, n;
        int con = 0;
        scanf("%d%d", &m, &n);
        for (int i = 0; i < m; i++) scanf("%s", &in[i][0]);
        for (int i = 0; i < n; i++)
        {
            memset(d, 0, sizeof(d));
            for (int j = 0; j < m; j++)
            {
                switch (in[j][i])
                {
                case 'A':
                    d[0]++;
                    break;
                case 'C':
                    d[1]++;
                    break;
                case 'G':
                    d[2]++;
                    break;
                case 'T':
                    d[3]++;
                    break;
                }
            }
            int re, maxd = -1;
            for (int j = 0; j < 4; j++)
            {
                if (d[j] > maxd)
                {
                    maxd = d[j];
                    re = j;
                }
            }
            switch (re)
            {
            case 0:
                putchar('A');
                break;
            case 1:
                putchar('C');
                break;
            case 2:
                putchar('G');
                break;
            case 3:
                putchar('T');
                break;
            }
            con += (m - maxd);
        }
        printf("\n%d\n", con);
    }
}
