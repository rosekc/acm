//2016-09-28-22.41
//UVa 1584

#include <cstdio>
#include <cstring>
using namespace std;

int len;
char in[105];
bool cmp(char* in, int p1, int p2)
{
    for (int i = 0; i < len; i++)
    {
        if (in[(p1 + i) % len] > in[(p2 + i) % len]) return 1;
        else if (in[(p1 + i) % len] < in[(p2 + i) % len]) return 0;
    }
}
void printre(char* in, int p)
{
    for (int i = 0; i < len; i++)
    {
        putchar(in[(p + i) % len]);
    }
    printf("\n");
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%s", in);
        len = strlen(in);
        int p = 0;
        for (int i = 1; i < len; i++)
        {
            if (cmp(in, p, i)) p = i;
        }
        printre(in, p);
    }
}
