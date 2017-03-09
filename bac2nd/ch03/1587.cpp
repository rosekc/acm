//2017-01-24-22.54
//Uva 1587

#include <bits/stdc++.h>
using namespace std;
pair<int, int> d[6];


int main()
{
    while (scanf("%d%d", &d[0].first, &d[0].second) != EOF)
    {
        if (d[0].first > d[0].second) swap(d[0].first, d[0].second);
        for (int i = 1; i <= 5; i++)
        {
            scanf("%d%d", &d[i].first, &d[i].second);
            if (d[i].first > d[i].second) swap(d[i].first, d[i].second);
        }
        sort(d, d + 6);
        bool f = 0;
        if (d[0] == d[1] && d[2] == d[3] && d[4] == d[5])
        {
            if (d[0].first == d[2].first)
            {
                pair<int, int> t = {d[0].second, d[2].second};
                if (t.first > t.second) swap(t.first, t.second);
                if (t == d[4]) f = 1;
            }
            else if (d[4].first == d[0].first)
            {
                pair<int, int> t = {d[0].second, d[4].second};
                if (t.first > t.second) swap(t.first, t.second);
                if (t == d[2]) f = 1;
            }
        }
        if (f) puts("POSSIBLE");
        else puts("IMPOSSIBLE");
    }
}
