#include <cstdio>
#include <algorithm>
using namespace std;

struct room
{
    int st;
    int ed;
    bool sta;
};
bool cmp(const room &a, const room &b)
{
    return a.st < b.st;
}
room d[100000 + 100];
int roomcon;
int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        int ret = 0;
        roomcon = 0;
        while (n--)
        {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            while (a--) d[roomcon++] = {b, b + c, 0};
        }
        sort(d, d + roomcon, cmp);
        int con = 0;
        for (int i = 1;;)
        {
            for (int j = 0; j < roomcon; j++)
            {
                if (!d[j].sta && d[j].st >= i)
                {
                    i = d[j].ed;
                    d[j].sta = 1;
                    con++;
                }
            }
            ret++;
            if (con == roomcon) break;
            i = 1;
        }
        printf("%d\n", ret, roomcon);
    }
}
