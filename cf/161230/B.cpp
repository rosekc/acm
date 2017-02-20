//2016-12-30-22.42
//B

#include <cstdio>
using namespace std;

int main()
{
    int n;
    char in[10];
    while (scanf("%d", &n) != EOF)
    {
        int x = 0;
        bool f = 1;
        int t;
        while (n--)
        {
            scanf("%d%s", &t, &in);
            if (!f) continue;
            switch (in[0])
            {
            case 'S':
                if (x == 20000) f = 0;
                x += t;
                    break;
            case 'W':
            case 'E':
                if (x == 20000 || x == 0) f = 0;
                break;
            case 'N':
                if (x == 0) f = 0;
                x -= t;
                break;
            default:
                break;
            }
            if (x < 0 || x > 20000) f = 0;
        }
        if (x != 0) f = 0;
        if (f) puts("YES");
        else puts("NO");
    }
}
