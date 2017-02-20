//hduacm 1091
#include <iostream>
using namespace std;

int main()
{
    int a, b;

    while( cin >> a >> b && ( a || b ) ) //要求a和b同时为0时才退出(terminates the input)
    {
        cout << a + b << endl;
    }
}
