//2016-09-26-20.18
//UVa10082

#include <cstdio>
#include <cstring>
using namespace std;

char data[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

int main()
{
    char c;
    int len = strlen(data);
    while ((c = getchar()) != EOF)
    {
        bool flag = 0;
        for (int i = 0; i < len; i++)
        {
            if (c == data[i]) {putchar(data[i - 1]); flag = 1; break;}
        }
        if (flag) continue;
        putchar(c);
    }
}
