//2016-09-26-22.28
//UVa401

#include <cstdio>
#include <cstring>
using namespace std;

char* data = "AEHIJMOSTUVWXYZ1815YXWVUT2OMLIH3A";
int len, dlen = strlen(data);
char* mes[] = {"a mirrored palindrome", "a regular palindrome", "a mirrored string", "not a palindrome"};
bool ismi(char* in, int i)
{
    for (int j = 0; j < dlen; j++)
    {
        if (in[i] == data[j])
        {
            if (in[len - i - 1] == data[dlen - j - 1]) return 1;
        }
    }
    return 0;
}
int main()
{
    char in[30];
    while (scanf("%s", in) != EOF)
    {
        len = strlen(in);
        bool f1 = 0, f2 = 0;
        for (int i = 0; i < (len + 1) / 2; i++)
        {
            if (!f1 && in[i] != in[len - i - 1]) f1 = 1;
            if (!f2 && !ismi(in, i)) f2 = 1;
            if (f1 && f2) break;
        }
        printf("%s -- is %s.\n\n", in, mes[(int(f1) << 1) ^ int(f2)]);
    }
}
