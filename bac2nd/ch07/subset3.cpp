//2017-03-09-14.02
//二进制法

#include <bits/stdc++.h>

using namespace std;

void print_subset(int n, int s)
{
    for (int i = 0; i < n; i++)
    {
        if (s & (1 << i)) printf("%d ", i);
    }
    puts("");
}

int main(){
    for (int i = 0; i < (1 << 4); i++)
    {
        print_subset(4, i);
    }
}
