//2017-03-09-13.12
//不重集排列

#include <bits/stdc++.h>

using namespace std;

void print_permutation(int n, int* A, int cur)
{
    if (cur == n)
    {
        for (int i = 0; i < n; i++)
        {
            printf("%d ", A[i]);
        }
        puts("");
    }
    else for (int i = 1; i <= n; i++)
    {
        int ok = 1;
        for (int j = 0; j < cur; j++)
        {
            if (A[j] == i) ok = 0;
        }
        if (ok)
        {
            A[cur] = i;
            print_permutation(n, A, cur + 1);
        }
    }
}
int A[20];
int main()
{
    print_permutation(3, A, 0);
}
