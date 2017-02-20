//2016-11-26-13.30
//I

#include <cstdio>
#include <set>
using namespace std;

int d;

int main()
{
    set<int> s;
    int t;
    d = 1;
    s.insert(d);
    for (int i = 0;; i++)
    {
        d *= 2;
        if (d > 0) s.insert(d);
        else break;
    }
    scanf("%d", &t);
    while (t--)
    {
        int in;
        scanf("%d", &in);
        if (s.count(in)) puts("Yes");
        else puts("No");
    }
}
