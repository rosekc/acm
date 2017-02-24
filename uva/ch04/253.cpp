//2017-02-23-14.50
//Uva 253

#include <bits/stdc++.h>

using namespace std;

struct node
{
    char _a, _b;
    node(){};
    bool ch = 0;
    node(char &a, char &b)
    {
        _a = a;
        _b = b;
        //if (_a > _b) swap(_a, _b);
    }
    bool operator == (const node &b)
    {
        return _a == b._a && _b == b._b;
    }
    bool operator < (const node &b)
    {
        if (_a == b._a) return _b < b._b;
        return _a < b._a;
    }
};
node c1[3], c2[3];
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    char in[20];
    while (scanf("%s", in) != EOF)
    {
        c1[0] = node(in[0], in[5]);
        c1[1] = node(in[1], in[4]);
        c1[2] = node(in[2], in[3]);
        c2[0] = node(in[6], in[11]);
        c2[1] = node(in[7], in[10]);
        c2[2] = node(in[8], in[9]);
        sort(in, in + 6);
        sort(in + 6, in + 12);
        if (memcmp(in, in + 6, sizeof char * 6) == 0)
        {
            int con = 0;
            for (int i = 0; i < 3; i++)
            {
                if (c1[i] == c2[i]) con++;
            }
        }
        //printf("%d\n", memcmp(c1, c2, sizeof c1));
        if (con % 2 == 0) puts("TRUE");
        else puts("FALSE");
    }
}
