#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 105;
struct wall
{
    int st;
    int ed;
    bool flag;
};
wall d[maxn];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int ret = 0;
        int w = 0;
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++)
        {
            scanf("%d%*d%d%*d", &d[i].st, &d[i].ed);
            if (d[i].st > d[i].ed) swap(d[i].st, d[i].ed);
            d[i].flag = 1;
            //printf("%d %d\n", d[i].st, d[i].ed);
            w = max(w, d[i].ed);
        }
        for (int i = 0; i <= w; i++)
        {
            start:
            int con = 0;
            int maxd = -1;
            int ind;
            for (int j = 0; j < n; j++)
            {
                if (d[j].flag && i >= d[j].st && i <= d[j].ed)
                {
                    con++;
                    if (maxd < d[j].ed - i)
                    {
                        maxd = d[j].ed - i;
                        ind = j;
                    }
                }
            }
            //printf("con: %d\n", con);
            if (con > m)
            {
                ret++;
                //printf("     %d\n", ind);
                d[ind].flag = 0;
                if (con - 1 > m) goto start;
            }
        }
        printf("%d\n", ret);
    }
}
