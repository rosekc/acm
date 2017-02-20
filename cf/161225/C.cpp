//2016-12-25-17.56
//C

#include <cstdio>
using namespace std;

int xp = 0, yp = 0, con = 0;;
void reset()
{
    xp = 0, yp = 0, con++;
}
int main()
{
    int n;
    char c;
    while (scanf("%d", &n) != EOF)
    {
        getchar();
        reset();
        while (n--)
        {
            scanf("%c", &c);
            //printf("%c %d\n", c, con);
            switch (c)
            {
            case 'R':
                if (xp == 0) xp = 1;
                else if (xp == -1)
                {
                    reset();
                    xp = 1;
                }
                break;
            case 'L':
                if (xp == 0) xp = -1;
                else if (xp == 1)
                {
                    reset();
                    xp = -1;
                }
                break;
            case 'U':
                if (yp == 0) yp = 1;
                else if (yp == -1)
                {
                    reset();
                    yp = 1;
                }
                break;
            case 'D':
                if (yp == 0) yp = -1;
                else if (yp == 1)
                {
                    reset();
                    yp = -1;
                }
                break;
            default:
                puts("sss");
                break;
            }
        }
        printf("%d\n", con);
        con = 0;
    }
}
