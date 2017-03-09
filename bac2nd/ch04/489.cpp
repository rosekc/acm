//2017-02-11-21.52
//Uva 489

#include <bits/stdc++.h>
using namespace std;

set<char> s;
char s1[100], s2[100];

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int con;
    while (scanf("%d", &con) != EOF && con != -1)
    {
        scanf("%s%s", s1, s2);
        s.clear();
        for (int i = 0; i < strlen(s1); i++)
        {
            s.insert(s1[i]);
        }
        int tc = 0;
        printf("Round %d\n", con);
        for (int i = 0; i < strlen(s2); i++)
        {
            if (s.find(s2[i]) != s.end()) s.erase(s2[i]);
            else tc++;

            if (tc > 6 || s.empty()) break;
        }

        if (tc > 6) puts("You lose.");
        else if (s.empty()) puts("You win.");
        else puts("You chickened out.");
    }
}
