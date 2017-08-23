//2017-08-18-14.02
//1001

#include <bits/stdc++.h>
using namespace std;

string s;

long long ans;
const int mod = 1000000007;
void addnum(int i)
{
    ans *= 10;
    ans += i;
    ans %= mod;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> s;
        ans = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                addnum(s[i] - '0');
            }
            else
            {
                i++;
                string t;
                long long a2 = 0;
                while (s[i] != ')')
                {
                    t = t + s[i];
                    i++;
                }
                //cout << t << endl;
                i += 3;
                while (s[i] != ')')
                {
                    a2 = a2 * 10;
                    a2 = a2 + s[i] - '0';
                    i++;
                }
                //cout << a2  << endl;
                for (long long j = 0; j < a2; j++)
                {
                    for (int k = 0; k < t.length(); k++)
                    {
                        addnum(t[k] - '0');
                    }
                }
            }
        }
        cout << ans << endl;
    }
}
