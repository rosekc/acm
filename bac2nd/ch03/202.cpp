 //2016-10-23-13.28
//UVa202

#include <cstdio>
using namespace std;
int d[6000];
int dsize;
int out[6000];
int outsize, st;
bool findd(int in)
{
    //printf("  %d\n", in);
    for (int i = 0; i < dsize; i++)
    {
        if (in == d[i]) {st = i; return 1;}
    }
    d[dsize++] = in;
    return 0;
}
int main()
{
    int a, b;
    while (scanf("%d%d", &a, &b) != EOF)
    {
        dsize = 0;
        outsize = 0;
        int t1 = a / b, t2 = a;
        printf("%d/%d = %d.", a, b, t1);
        while (1)
        {
            t2 -= (t1 * b);
            t2 *= 10;
            if (findd(t2)) break;
            t1 = t2 / b;
            out[outsize++] = t1;
        }
        for (int i = 0; i < outsize; i++)
        {
            if (i == st) printf("(");
            printf("%d", out[i]);
            if (i > 48)
            {
                printf("...");
                break;
            }
        }
        printf(")\n   %d = number of digits in repeating cycle\n\n", outsize - st);
    }
}
