#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int maxn = 500 + 10;
bool data[maxn][maxn];
int indge[maxn], cnt;
bool select[maxn];

int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        memset(data, 0, sizeof(data));
        memset(indge, 0, sizeof(indge));
        cnt = 0;
        int a, b;
        bool flag = 1;
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d", &a, &b);
            if (data[a][b] == 0)
            {
                indge[b]++;
                data[a][b] = 1;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (indge[i] == 0)
            {
                select[i] = 1;
                cnt++;
            }
        }
        while (cnt != 0)
        {
            int p = 600;
            for (int i = 1; i <= n; i++)
                if (select[i])
                {
                    p = min(i, p);
                }
            //puts("123");
            select[p] = 0;
            cnt--;
            if (flag) printf("%d", p);
            else printf(" %d", p);
            flag = 0;
            for (int i = 1; i <= n; i++)
            {
                if (data[p][i])
                {
                    if (--indge[i] == 0)
                    {
                        //printf("  %d\n", i);
                        select[i] = 1;
                        cnt++;
                    }
                }
            }
        }
        printf("\n");
    }
}