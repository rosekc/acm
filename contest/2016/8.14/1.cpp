#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int main()
{
    freopen("D:\\input.txt", "w", stdout);
    int tmp = 10001;
    for (int j = 100000; j <= 1000000; j++)
    {
        printf("%d", tmp * j);
        printf("\n");
    }
}
