//2016-12-24-12.15
//C

#include <cstdio>
#include <set>
using namespace std;
set<int> s1, s2;
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, t;
        s1.clear();
        s2.clear();
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &t);
            if (s2.count(t) == 1) continue;
            if (s1.count(t) == 1)
            {
                s2.insert(t);
            }
            else s1.insert(t);
        }
        if (s2.size() == 0) puts("none");
        else
        {
            set<int>::iterator it;
            bool isfirst = 1;
            for (it = s2.begin(); it != s2.end(); it++)
            {
                if (isfirst) isfirst = 0;
                else printf(" ");
                printf("%d", *it);
            }
            puts("");
        }
    }
}
