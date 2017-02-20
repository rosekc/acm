#include <cstdio>
#include <cstring>
const int maxn = 10000 + 10;
bool isp[maxn];

int main()
{
    int n, m, t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &m);
        memset(isp, 0, sizeof(isp));
        isp[0] = 1;
        for (int i = 1; i <= n && i <= m; i++)
        {
            isp[i] = 0;
        }
        for (int i = m + 1; i <= n; i++)
        {
            //printf("123\n");
            bool flag = 0;
            for (int j = i - 1; j >= i - m; j--)
            {
                //printf("j:%d\n", j);
                if (isp[j])
                {
                    //printf("%d\n", j);
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                //printf("123dd\n");
                isp[i] = 1;
            }
        }
        if (!isp[n]) printf("Grass\n");
        else printf("Rabbit\n");
    }
}
