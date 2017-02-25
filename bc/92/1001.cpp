//2017-02-25-18.58
//1001

#include <bits/stdc++.h>

using namespace std;

map<string, vector<int> > m;

int main()
{
    int t, n, d;
    string in;
    scanf("%d", &t);
    while (t--)
    {
        m.clear();
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            cin >> in >> d;
            m[in].push_back(d);
        }
        int ans = 0;
        for (auto i : m)
        {
            sort(i.second.begin(), i.second.end());
            ans += *(i.second.end() - 1);
            ans += i.second.size() == 1 ? 0 : *(i.second.end() - 2);
            //printf("%d\n", ans);
        }
        printf("%d\n", ans);

    }
}
