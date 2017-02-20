#include <cstdio>

using namespace std;

char in[60];

int getret()
{
    int ind = 0;
    while (in[ind] != '=') ind++;
    ind++;
    int p1 = 1;
    int ret = 0;
    bool flag = 0;
    if (in[ind] >= '2' && in[ind] <= '9')
    {
        p1 = in[ind] - '0';
    }
    while (1)
    {
        int t = 0;
        int p = 1;
        while (1)
        {
            switch (in[ind])
            {
            case 'N':
                if (in[ind + 1] == 'a')
                {
                    t += 23;
                    ind++;
                }
                else t += 14;
                break;
            case 'C':
                if (in[ind + 1] == 'a')
                {
                    t += 40;
                    ind++;
                }
                else if (in[ind + 1] == 'l')
                {
                    t += 35;
                    ind++;
                }
                else t += 12;
                break;
            case 'O':
                t += 16;
                break;
            case 'S':
                t += 32;
                break;
            case 'H':
                t += 2;
                break;
            case 'A':
                t += 27;
                ind++;
                break;
            case 'Z':
                t += 65;
                ind++;
                break;
            }
            ind++;
            if (in[ind] == ')')
            {
                flag = 0;
                ind++;
            }
            if (flag == 0) break;
        }
        if (in[ind] >= '2' && in[ind] <= '9')
        {
            p = in[ind++] - '0';
        }
        ret += p * t;
        if (in[ind] == '+' || in[ind] == '\0') break;
        if (in[ind] == '(')
        {
            flag = 1;
            ind++;
        }
    }
    return p1 * ret;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%s", in);
        printf("%04d\n", getret());
    }
}
