//2016-09-17-16.23
//qingdao inter 1002

#include <iostream>
#include <sstream>
#include <string>
#include <cstdio>
using namespace std;
double d[1000000 + 10];
int main()
{
    d[1] = 1;
    for (int i = 2; i <= 1000000; i++)
    {
        d[i] = d[i - 1] + (1.0 / i / i);
    }
    int n;
    string in;
    while (cin >> in)
    {
        if (in.size() > 7)
        {
            printf("1.64493\n");
            continue;
        }
        stringstream ss;
        ss << in;
        ss >> n;
        if (n > 1000000)
        {
            printf("1.64493\n");
            continue;
        }
        else
        {
            printf("%.5lf", d[n]);
        }
    }
}
