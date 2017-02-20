#include <cstdio>

using namespace std;

bool flag;

int check()
{
    int a, b, c, d;
    int lw, rw;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    if (a == 0)
    {
        a = check();
    }
    if (c == 0)
    {
        c = check();
    }
    if (a * b != c * d) flag = 0;

    return a + c;
}

int main()
{
    //freopen("C:\\Users\\Administrator\\Desktop\\output.txt","w",stdout);
    //freopen("C:\\Users\\Administrator\\Desktop\\input.txt","r",stdin);
    int t;
    scanf("%d", &t);

    while (t--)
    {
        flag = 1;
        check();
        if (flag) printf("YES\n");
        else printf("NO\n");
        if(t != 0) printf("\n");
    }
}
