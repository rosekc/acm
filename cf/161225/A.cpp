//2016-12-25-17.19
//A

#include <cstdio>
using namespace std;

int main()
{
    int n, m, k;
    while (scanf("%d%d%d", &n, &m, &k) != EOF)
    {
        bool f;
        if (k % 2 == 0)
        {
            k = k >> 1;
            f = 1;
        }
        else {k = (k >> 1) + 1; f = 0;}
        if (k % m == 0)
        {
            printf("%d %d %c\n", k / m, m, f ? 'R' : 'L');
        }
        else printf("%d %d %c\n", k / m + 1, k % m, f ? 'R' : 'L');
    }
}
