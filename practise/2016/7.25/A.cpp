#include <cstdio>

using namespace std;

int pre[1001];
int in[1001];

void getpostorder(int preind, int inind, int n, bool isroot)
{
    if (n == 1)
    {
        printf("%d ", pre[preind]);
        return;
    }
    else if (n <= 0) return;
    int i;
    for (i = 0; pre[preind] != in[inind + i]; i++);
    getpostorder(preind + 1, inind, i, 0);
    getpostorder(preind + i + 1, inind + i + 1, n - i - 1, 0);
    if (isroot) printf("%d", pre[preind]);
    else printf("%d ", pre[preind]);
}

int main()
{
    int n;

    while (scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &pre[i]);
        }
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &in[i]);
        }
        getpostorder(0, 0, n, 1);
        printf("\n");
    }
}
