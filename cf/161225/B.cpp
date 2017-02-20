//2016-12-25-17.34
//B

#include <cstdio>
#include <string>
#include <iostream>
#include <cstring>
using namespace std;
char dic[30];
int main()
{
    string s1, s2;
    while (cin >> s1 >> s2)
    {
        memset(dic, 0, sizeof(dic));
        bool f = 1;
        for (int i = 0; i < s1.length(); i++)
        {
            if (!f) continue;
            if (s1[i] == s2[i])
            {
                if (dic[s1[i] - 'a'] == 0) dic[s1[i] - 'a'] = s1[i];
                else if (dic[s1[i] - 'a'] != s1[i])
                {
                    puts("-1");
                    f = 0;
                }
            }
            else
            {
                if (dic[s1[i] - 'a'] == 0 && dic[s2[i] - 'a'] == 0)
                {
                    dic[s1[i] - 'a'] = s2[i];
                    dic[s2[i] - 'a'] = s1[i];
                }
                else if (dic[s1[i] - 'a'] != s2[i] && dic[s2[i] - 'a'] != s1[i])
                {
                    puts("-1");
                    f = 0;
                }
            }
        }
        if (!f) continue;
        int con = 0;
        for (int i = 0; i < 26; i++)
        {
            if (dic[i] != 0 && dic[i] != (i + 'a')) con++;
        }
        printf("%d\n", con / 2);
        for (int i = 0; i < 26; i++)
        {
            if (dic[i] != (i + 'a') && dic[i] != 0)
            {
                printf("%c %c\n", (i + 'a'), dic[i]);
                dic[dic[i] - 'a'] = 0;
            }
        }
    }
}
