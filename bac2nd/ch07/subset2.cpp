//2017-03-09-13.55
//位向量法

#include <bits/stdc++.h>

using namespace std;

void print_subset(int n, int* B, int cur)
{
    if (cur == n)
    {
        for (int i = 0; i < cur; i++)
        {
            if (B[i]) printf("%d ", i);
        }
        puts("");
        return;
    }
    B[cur] = 1;
    print_subset(n, B, cur + 1);
    B[cur] = 0;
    print_subset(n, B, cur + 1);
}

int B[4];
int main(){
    print_subset(4, B, 0);
}
