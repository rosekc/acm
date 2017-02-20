#include <cstdio>
#include <algorithm>
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
        int x, y;
        char str[2];
        int con = 0;
        for (int i = 0; i < m; i ++)
        {
            scanf("%d %s %d", &x, str, &y);
            if (str[0] == '=' && x < y)
            {
                swap(x, y);
            }
            else if(str[0] == '<')
            {
                swap(x, y);
            }
            if (data[x][y] == 0)
            {
                indge[y]++;
                data[x][y] = 1;
                printf("%d %d\n", x, y);
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (indge[i] == 0)
            {
                q.push(i);
                printf("%d\n", i);
            }
        }
        while (!q.empty())
        {
            int p = q.top();
            con++;
            q.pop();
            for (int i = 0; i < n; i++)
            {
                if(data[p][i])
                {
                    if (--indge[i] == 0)
                    {
                        printf("%d\n", i);
                        q.push(i);
                    }
                }
            }
        }
        printf("%d %d\n", con, n);
        if (con == n) printf("OK\n");
        else printf("CONFLICT\n");
    }
}
