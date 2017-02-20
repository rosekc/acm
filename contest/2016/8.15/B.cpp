#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 1000 + 50;
bool notprime[maxn];

int main()
{
    memset(notprime, 0, sizeof(notprime));
    notprime[1] = 1;
    for (int i = 2; i < maxn; i++)
    {
        if (!notprime[i])
        {
            for (int j = i * i; j < maxn; j += i)
            {
                notprime[j] = 1;
            }
        }
    }
    int n;
    scanf("%d", &n);
    while (n--)
    {
        int i = 0;
        int in;
        scanf("%d", &in);
        while (1)
        {
            if (in + i < maxn && !notprime[in + i])
            {
                printf("%d\n", in + i);
                break;
            }
            if (in - i > 1 && !notprime[in - i])
            {
                printf("%d\n", in - i);
                break;
            }
            i++;
        }
    }
}
