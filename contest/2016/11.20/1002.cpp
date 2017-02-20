//2016-11-20-12.14
//

#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 10010;
long long d[maxn][maxn], mr[maxn], mc[maxn];

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        int con = 0;
        memset(mr, 0x3f, sizeof(mr));
        memset(mc, 0, sizeof(mc));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                scanf("%d", &d[i][j]);
                if (d[i][j] < mr[i]) mr[i] = d[i][j];
                if (d[i][j] > mc[j]) mc[j] = d[i][j];
            }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
        {
                if (d[i][j] == mr[i] && d[i][j] == mc[j]){ con++; }
        }
        printf("%d\n", con);
    }
}
