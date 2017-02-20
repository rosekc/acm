#include <cstdio>


int a[100000 + 10];
int f(int l, int r)
{
    if (l == r) return a[l];
    else return f(l, r - 1) % a[r];
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, q, l, r;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
        }
        scanf("%d", &q);
        while (q--)
        {
            scanf("%d%d", &l, &r);
            printf("%d\n", f(l, r));
        }
    }
}
