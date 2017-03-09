//2017-03-09-13.22
//生成可重集的排列

#include <bits/stdc++.h>

using namespace std;
void print_permutation(int n, int* P, int* A, int cur)
{
    if (cur == n)
    {
        for (int i = 0; i < n; i++)
        {
            printf("%d ", A[i]);
        }
        puts("");
    }
    else for (int i = 0; i < n; i++) if (!i || P[i] != P[i - 1])
    {
        int c1 = 0, c2 = 0;
        for (int j = 0; j < cur; j++)
        {
            if (A[j] == P[i]) c1++;
        }
        for (int j = 0; j < n; j++)
        {
            if (P[j] == P[i]) c2++;
        }
        if (c1 < c2)
        {
            A[cur] = P[i];
            print_permutation(n, P, A, cur + 1);
        }
    }
}
int A[10], P[] = {1, 1, 2, 3};
int main()
{
    print_permutation(4, P, A, 0);
}
