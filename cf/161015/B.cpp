//2016-10-15-17.32
//B

#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
char in[1010];
int a = 0, b = 0, c = 0;
bool isnum(char &in)
{
    return in >= '0' && in <= '9';
}
int get(int i)
{
    int aa = atoi(&in[i]);
    int ia = i;
    printf("%d\n", atoi(&in[i]));
    while (isnum(in[i]))
    {
        i;
    }
    if (in[i] != '.') goto exit;
    else i++;
    printf("%d\n", atoi(&in[i]));
    int bb = atoi(&in[i]);
    int ib = i;
    while (b >= 1000) {b -= 1000; a++;}
    while (isnum(in[i]))
    {
        i++;
    }
    if (in[i] != '.')
    {
        goto exit;
    }
    else i++;
    printf("%d\n", atoi(&in[i]));
    c += atoi(&in[i]);
    while (c >= 100)
    {
        b++;
        while (b >= 1000) {b -= 1000; a++;}
        c -= 100;
    }
    exit:
    while (isnum(in[i])) i++;
    return i;
}

int main()
{
    while (scanf("%s", in) != EOF)
    {
        a = 0, b = 0, c = 0;
        int len = strlen(in);
        for (int i = len - 1; i >= 0; i++)
        {
            if (isnum(in[i])) i = get(i);
        }
        if (a != 0) printf("%d", a);
        if (c != 0) printf(".%d.%d", b, c);
        else if (b != 0) printf(".%d", b);
        printf("\n");
    }
}
