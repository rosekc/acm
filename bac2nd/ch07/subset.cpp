//2017-03-09-13.47
//增量构造法

#include <bits/stdc++.h>

using namespace std;

void print_subset(int n, int* A, int cur)
{
    for (int i = 0; i < cur; i++)
    {
        printf("%d ", A[i]);
    }
    puts("");
    int s = cur ? A[cur - 1] + 1 : 0;
    for (int i = s; i < n; i++)
    {
        A[cur] = i;
        print_subset(n, A, cur + 1);
    }
}

int A[4];
int main()
{
    print_subset(4, A, 0);
}
