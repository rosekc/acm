//2016-10-31-22.11
//

#include <cstdio>
#include <cstring>
using namespace std;
char in[105];
int main()
{
    while (scanf("%s", in) != EOF)
    {
        int len = strlen(in);
        int mp = 0, p = 1;
        for (int i = 0;; i++)
        {
            if (in[i] == 'A' || in[i] == 'E' || in[i] == 'I' || in[i] == 'O' || in[i] == 'U' || in[i] == 'Y')
            {
                if (p > mp) mp = p;
                p = 1;
            }
            else p++;
            if (i == len - 1)
            {
                if (p > mp) mp = p;
                break;
            }
        }
        printf("%d\n", mp);
    }
}
