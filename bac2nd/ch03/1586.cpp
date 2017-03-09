//2016-09-28-23.05
//UVa 1586

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
        int len = strlen(in);
        double ret = 0;
        for (int i = 0; i < len; i++)
        {
            int p = -1;
            double n;
            switch(in[i])
            {
            case 'C':
                n = 12.01;
                break;
            case 'H':
                n = 1.008;
                break;
            case 'O':
                n = 16;
                break;
            case 'N':
                n = 14.01;
                break;
            default:
                break;
            }
            while (in[i + 1] >= '0' && in[i + 1] <= '9')
            {
                if (p == -1) p = in[i + 1] - '0';
                else p = p * 10 + (in[i + 1] - '0');
                i++;
            }
            if (p != -1) ret += p * n;
            else ret += n;
        }
        printf("%.3f\n", ret);
    }
}
