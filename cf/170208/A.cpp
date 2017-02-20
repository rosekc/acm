//2017-02-08-14.09
//A

#include <bits/stdc++.h>
using namespace std;
const int maxn = 10e5 + 10;
char s1[maxn], s2[maxn];
int len1, len2;
int main()
{
    scanf("%s%s", s1, s2);
    len1 = strlen(s1);
    len2 = strlen(s2);
    int f = 1;
    if (len1 != len2)
    {
        printf("%d\n", max(len1, len2));
        return 0;
    }
    else
    {
        for (int i = 0; i < len1; i++)
        {
            if (s1[i] != s2[i]) f = 0;
        }
    }
    if (f) puts("-1");
    else printf("%d\n", len1);
}
