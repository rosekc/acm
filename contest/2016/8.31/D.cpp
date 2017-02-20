#include <cstdio>
#include <cstring>
int d[10000];
int f(int n)
{
    if (n == 1) return d[n] = 1;
    if (d[n] != -1) return d[n];
    else return d[n] = f(n - 1) + n;
}

int main()
{
    int in;
    memset(d, -1, sizeof(d));
    //for (int i = 1; i < 1000; i++) printf("%d\n", f(i));
    while (scanf("%d", &in) != EOF)
    {
        int t = 1;
        for (int i = 2;;i++)
        {
            t += f(i);
            //printf("%d\n", t);
            if (t > in)
            {
                printf("%d\n", i - 1);
                break;
            }
        }
    }
}
