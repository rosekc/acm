//2016-10-15-18.34
//

#include <cstdio>
using namespace std;
int out[5010];
int main()
{
    int n;
    scanf("%d", &n) != EOF;
    {
        int a1, a2, a3;
        printf("? 1 2\n");
        fflush(stdout);
        scanf("%d", &a1);
        printf("? 1 3\n");
        fflush(stdout);
        scanf("%d", &a2);
        printf("? 2 3\n");
        fflush(stdout);
        scanf("%d", &a3);
        out[1] = (a1 + a2 - a3) / 2;
        out[2] = a1 - out[1];
        out[3] = a2 - out[1];
        for (int i = 4; i <= n; i++)
        {
            printf("? 1 %d\n", i);
            fflush(stdout);
            scanf("%d", &a1);
            out[i] = a1 - out[1];
        }
        printf("! ");
        for (int i = 1;; i++)
        {
            printf("%d", out[i]);
            if (i != n) printf(" ");
            else break;
        }
        printf("\n");
    }
}
