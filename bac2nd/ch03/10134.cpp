//2016-10-27-20.27
//UVa10340

#include <cstdio>
#include <cstring>
using namespace std;
char s[1000000], t[1000000];

int main()
{
    while (scanf("%s%s", s, t) != EOF)
    {
        int i1 = 0, i2 = 0;
        int lens = strlen(s), lent = strlen(t);
        bool f = 0;
        for (;i2 < lent; i2++)
        {
            if (s[i1] == t[i2]) i1++;
            if (i1 == lens) {f = 1; break;}
        }
        if (f) puts("YES");
        else puts("NO");
    }
}
