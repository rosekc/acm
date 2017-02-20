#include <cstdio>
#include <cstring>
using namespace std;

char in[10000000 + 50];

int main()
{
    freopen("D:\\input.txt", "r", stdin);
    int con = 1;
    while (scanf("%s", in) != EOF)
    {
        int flag = 0;
        int st = 0;
        int len = strlen(in);
        while (len - st >= 2 && in[st] == '0' && in[st] != '\0') st++;
        //len -= st;
        //printf("%d %d\n", st, len);
        if (len - st >= 5 && in[st] == in[st + 4])
        {
            flag = 1;
            for (int i = st; i < len; i++)
            {
                if (i == st || i == st + 4) continue;
                if (in[i] != '0')
                {
                    flag = 0;
                    break;
                }
            }
        }
        printf("Case #%d: ", con++);
        if (flag || (len - st == 1 && in[st] == '0')) printf("YES\n");
        else printf("NO\n");
    }
}
