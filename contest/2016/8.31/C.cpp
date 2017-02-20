#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int main()
{
    string in;
    long long tmp;
    stringstream ss;
    while (cin >> in)
    {
        if (in.size() > 11) cout << "TAT\n";
        else
        {
            ss << in;
            ss >> tmp;
            if (tmp >= 4294967296 || tmp == 0) cout << "TAT\n";
            else if (tmp >= 65536) cout << "5\n";
            else if (tmp >= 256) cout << "4\n";
            else if (tmp >= 16) cout << "3\n";
            else if (tmp >= 4) cout << "2\n";
            else cout << "1\n";
        }
        ss.clear();
    }
}
