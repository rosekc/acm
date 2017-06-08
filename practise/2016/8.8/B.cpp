#include <cstdio>
#include <map>
#include <cstring>
#include <string>
using namespace std;

int re[20010];
int n, m;
map<string, int> data;

int main()
{
    while (scanf("%d%d", &n, &m) && m + n != 0)
    {
        memset(re, 0, sizeof(re));
        data.clear();
        for (int i = 0; i < n; i++)
        {
            char in[26];
            scanf("%s", in);
            string tmp = in;
            data[tmp]++;
        }
        map<string, int>::iterator iter;
        for (iter = data.begin(); iter != data.end(); iter++)
        {
            re[iter->second]++;
        }
        for (int i = 1; i <= n; i++)
        {
            printf("%d\n", re[i]);
        }
    }
}
