//2016-10-15-17.11
//cf

#include <cstdio>
using namespace std;

int re[400];

int main()
{
    int a, b;

    while (scanf("%d%d", &a, &b) != EOF)
    {
        re[0] = b;
        bool flag = 1;
        int i;
        for (i = 0;; i++)
        {
            if (re[i] == a) break;
            if (re[i] < a) {flag = 0; break;}
            if (re[i] % 2 == 0 && re[i] != 0) re[i + 1] = re[i] / 2;
            else if (re[i] % 10 == 1) re[i + 1] = re[i] / 10;
            else {flag = 0; break;}
        }
        if (!flag) {puts("NO"); continue;}
        printf("YES\n%d\n", i + 1);
        for (;; i--)
        {
            printf("%d", re[i]);
            if (i == 0) break;
            else printf(" ");
        }
        printf("\n");
    }
}
