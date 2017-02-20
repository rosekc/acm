#include <cstdio>

int main()
{
    int t;
    long long n;
    while (scanf("%d%I64d", &t, &n) != EOF)
    {
        int con = 0;
        while (t--)
        {
            char in[3];
            int q;
            scanf("%s%d", in, &q);
            if (in[0] == '+')
            {
                n += q;
            }
            else
            {
                if (q > n)
                {
                    con++;
                    continue;
                }
                else
                {
                    n -= q;
                }
            }
        }
        printf("%I64d %d\n", n, con);
    }
}
