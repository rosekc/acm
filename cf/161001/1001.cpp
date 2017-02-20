//2016-10-01-21.46
//

#include <cstdio>
using namespace std;
char in[8];

int main()
{
    int t;
    while (scanf("%d%s", &t, in) != EOF)
    {
        if (in[3] > '5') in[3] = '0';
        if (t == 12)
        {
            if (in[0] > '1')
            {
                if (in[1] == 0) in[0] = '1';
                else in[0] = '0';
            }
            else if (in[0] == '1')
            {
                if (in[1] > '2') in[1] = '0';
            }
            if (in[0] == '0')
            {
                if (in[1] == '0') in[0] = '1';
            }
        }
        else
        {
            if (in[0] > '2') in[0] = '0';
            else if (in[0] == '2')
            {
                if (in[1] > '3') in[1] = '0';
            }
        }
        printf("%s\n", in);
    }
}
