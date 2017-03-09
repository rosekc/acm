//2017-03-03-12.26
//Uva 253

#include <bits/stdc++.h>

using namespace std;

char a[20], b[10];
int main()
{
    while (scanf("%s", &a) != EOF)
    {
        memcpy(b, a + 6, sizeof(char) * 6);
        int f = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                if (a[i] == b[j] && a[5 - i] == b[5 - j])
                {
                    f++;
                    a[i] = b[j] = '0';
                    a[5 - i] = b[5 - j] = '1';
                    break;
                }
            }
        }
        if (f == 3) puts("TRUE");
        else puts("FALSE");
    }
}
