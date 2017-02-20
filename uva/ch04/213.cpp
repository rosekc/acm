//2017-02-11-23.16
//Uva 213

#include <bits/stdc++.h>
using namespace std;

int readchar()
{
    char ch;
    do ch = getchar();
    while (ch == '\n' || ch == '\r');
    return ch;
}

int readint(int c)
{
    int w = 0;
    while (c--)
    {
        w = readchar() - '0' + (w << 1);
    }
    return w;
}

int code[8][1 << 8];
int readcodes()
{
    memset(code, 0, sizeof code);
    for (int len = 1; len <= 7; len++)
        for (int i = 0; i < (1 << len) - 1; i++)
    {
        int ch;
        if (len != 1) ch = getchar();
        else ch = readchar();
        if (ch == EOF) return 0;
        if (ch == '\n' || ch == '\r') return 1;
        code[len][i] = ch;
    }
}
int main()
{
    while (readcodes())
    {
        while (1)
        {
            int len = readint(3);
            if (len == 0) break;
            while (1)
            {
                int v = readint(len);
                if (v == (1 << len) - 1) break;
                putchar(code[len][v]);
            }
        }
        puts("");
    }
}
