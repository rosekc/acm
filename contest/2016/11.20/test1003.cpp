//2016-11-23-23.24
//

#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <cmath>
using namespace std;

int main()
{
    srand(time(0));
    long long h, n;
    h = (rand() % 49) + 1;
    n = (rand() / (double)RAND_MAX) * (pow(2, h) - 1) + 1;
    printf("%lld %lld\n", h, n);
}
