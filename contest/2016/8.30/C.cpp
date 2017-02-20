#include <cstdio>

using namespace std;
char s[100000 + 5];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int len;
        scanf("%d", &len);
        if (len == 0)
        {
            puts("No");
            continue;
        }
        scanf("%s", s);
        if (len % 2 == 1 || len == 2)
        {
            puts("No");
            continue;
        }
        int con = 0;
        bool flag = 1;
        for (int i = 0; i < len; i++)
        {
            if (s[i] == '(')
            {
                con++;
            }
            else
            {
                if (con == 0)
                {
                    if (flag)
                    {
                        flag = 0;
                        con++;
                    }
                    else
                    {
                        break;
                    }
                }
                else
                    con--;
            }
        }
        if ((flag && con == 0) || (!flag && con == 2))
        {
            puts("Yes");
        }
        else puts("No");
    }
}
