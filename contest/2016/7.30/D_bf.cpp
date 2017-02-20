#include <cstdio>
#include <algorithm>

using namespace std;

int q[100000 + 20];
bool s[100000 + 20];

int main()
{
    int con = 1;
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, m;
        unsigned long long ret = 1;
        scanf("%d%d", &n, &m);
        printf("Case #%d:\n", con++);
        for (int i = 0; i < n; i++)
        {
            int j;
            scanf("%d%d", &j, &q[i]);
            if (j == 2)
            {
                s[i] = 0;
                s[q[i] - 1] = 0;
                ret = 1;
                for (int k = 0; k <= i; k++)
                {
                    if (s[k] == 1) ret = (ret * q[k]) % m;
                }
            }
            else
            {
                s[i] = 1;
                ret = (ret * q[i]) % m;
            }
            //else f = 1;
            printf("%I64u\n", ret);
        }
    }
}
