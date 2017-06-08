#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int maxn = 500 + 10;
bool data[maxn][maxn];
int indge[maxn];
priority_queue< int, vector<int>, greater<int> > q;

int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        memset(data, 0, sizeof(data));
        memset(indge, 0, sizeof(indge));
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
            if (indge[i] == 0) q.push(i);
        }
        while (!q.empty())
        {
            int p = q.top();
            if (flag) printf("%d", p);
            else printf(" %d", p);
            flag = 0;
            q.pop();
            for (int i = 1; i <= n; i++)
            {
                if (data[p][i])
                {
                    if (--indge[i] == 0)
                    {
                        //printf("  %d\n", i);
                        q.push(i);
                    }
                }
            }
        }
        printf("\n");
    }
}
