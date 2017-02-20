//2016-12-10-10.23
//A

#include <cstdio>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, con = 0, tmp;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &tmp);
            if (tmp) con++;
        }
        printf("%.2f\n", con * 1.0 / n);
    }
}
