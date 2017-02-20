//2017-02-11-21.32
//Uva 1339

#include <bits/stdc++.h>
using namespace std;

const int maxn = 110;
char s1[maxn], s2[maxn];
int cnt1[26], cnt2[26];

int main()
{
    while (scanf("%s%s", s1, s2) != EOF)
    {
        memset(cnt1, 0, sizeof cnt1);
        memset(cnt2, 0, sizeof cnt1);
        for (int i = 0; i < strlen(s1); i++)
        {
            cnt1[s1[i] - 'A']++;
            cnt2[s2[i] - 'A']++;
        }
        sort(cnt1, cnt1 + 26);
        sort(cnt2, cnt2 + 26);
        if (memcmp(cnt1, cnt2, sizeof cnt1) == 0) puts("YES");
        else puts("NO");
    }
}
