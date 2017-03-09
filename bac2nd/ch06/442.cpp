//Uva 442
//2016-09-12

#include <cstdio>
#include <stack>
#include <iostream>
#include <string>
using namespace std;
struct Matrix
{
    int r, c;
    Matrix(int r = 0, int c = 0): r(r), c(c) {}
};
Matrix data[26];
stack<Matrix> sta;
int main()
{
    int n;
    scanf("%d", &n);
    while (n--)
    {
        char s[2];
        int r, c;
        scanf("%s %d%d", s, &r, &c);
        data[int(s[0] - 'A')].r = r;
        data[int(s[0] - 'A')].c = c;
    }
    string in;
    while (cin >> in)
    {
        int len = in.size();
        int ans = 0;
        bool flag = 0;
        for (int i = 0; i < len; i++)
        {
            if (in[i] >= 'A' && in[i] <= 'Z') sta.push(data[in[i] - 'A']);
            else if (in[i] == ')')
            {
                Matrix m2 = sta.top();
                sta.pop();
                Matrix m1 = sta.top();
                sta.pop();
                if (m1.c != m2.r)
                {
                    flag = 1;
                    break;
                }
                ans += m1.c * m1.r * m2.c;
                sta.push(Matrix(m1.r, m2.c));
            }
        }
        if (flag) puts("error"); else printf("%d\n", ans);
    }
}
