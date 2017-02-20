#include <cstdio>
#include <algorithm>
using namespace std;
int d[100 + 5];
int n;
bool getsta(int i, bool s)
{
    if (i == 0) return 0;
    if (i == 3) return 1;
    if (i == 1 && s) return 1;
    if (i == 2 && !s) return 1;
    return 0;
}
int findday(int i, bool s)
{
    if (i > n) return 0;
    //printf("%d %d %d\n", i, s, getsta(d[i], s));
    if (getsta(d[i], s)) return 1 + findday(i + 1, !s);
    else return 0;
}
int main()
{
    while (scanf("%d", &n) != EOF)
    {
        int con = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &d[i]);
        }
        for (int i = 1; i <= n; i++)
        {
            if (d[i] == 0) con++;
            else
            {
                int t = max(findday(i, 1), findday(i, 0));
                //printf("re:%d %d %d\n", i, findday(i, 1), findday(i, 0));
                i += t;
                //printf("i:%d\n", i);
                if(i <= n) con++;
            }
        }
        printf("%d\n", con);
    }
}
