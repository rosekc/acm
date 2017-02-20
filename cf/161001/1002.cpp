//2016-10-01-22.39
//

#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int n;
    char in[120];
    int s[120];
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < n; i++) scanf("%d", &s[i]);
        int con = 0, l = 0;
        bool flag = 0;
        getchar();
        while (gets(in) != NULL)
        {
            con = 0;
            int len = strlen(in);
            for (int i = 0; i < len; i++)
            {
                char &c = in[i];
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y')
                {
                    con++;
                }
            }
            if (s[l] != con)
            {
                flag = 1;
            }
            if (l == n - 1) break;
            l++;
        }
        if (flag) puts("NO");
        else puts("YES");
    }
}
