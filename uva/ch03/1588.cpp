//2017-01-25-14.27
//Uva 1588

#include <bits/stdc++.h>
using namespace std;

char d1[105], d2[105];
int len1, len2;
bool check(int i, int j)
{
    int i1 = i,  j1 = j;
    while (i1 < len1 && j1 < len2)
    {
        if (d1[i1++] == '2' && d2[j1] == '2')
        {
            //printf("  %d %d\n", i1, j1);
            return 0;
        }
        j1++;
    }
    //printf("%d %d\n", i1, j1);
    return 1;
}

int main()
{
    while (scanf("%s%s", d1, d2) != EOF)
    {
        len1 = strlen(d1);
        len2 = strlen(d2);
        int re = 2000;
        for (int i = 0; i < len1; i++)
        {
            if (check(i, 0)) re = min(re, max(i + len2, len1));
        }
        for (int i = 0; i < len2; i++)
        {
            if (check(0, i)) re = min(re, max(i + len1, len2));
        }
        re = min(len2 + len1, re);
        printf("%d\n", re);
    }
}
