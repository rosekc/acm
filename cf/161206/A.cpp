//2016-12-06-22.38
//A

#include <cstdio>
using namespace std;

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        if (n == 0) {puts("1"); continue;}
        switch (n % 4)
        {
        case 0:
            puts("6");
            break;
        case 1:
            puts("8");
            break;
        case 2:
            puts("4");
            break;
        case 3:
            puts("2");
            break;
        }
    }
}
