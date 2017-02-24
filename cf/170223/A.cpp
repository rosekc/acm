//2017-02-23-22.33
//A

#include <bits/stdc++.h>

using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;
    int n;
    cin >> n;
    cout << a << " " << b << endl;
    while (n--)
    {
        string in1, in2;
        cin >> in1 >> in2;
        if (a == in1) a = in2;
        else b = in2;
        cout << a << " " << b << endl;
    }
}
