#include <iostream>
#include <string>

using namespace std;

void getnext( string pattern, int next[] )
{
    unsigned int i, t;

    int length = pattern.size();

    i = 1;
    t = 0;
    next[1] = 0;

    while(i < length + 1)
    {
        while(t > 0 && pattern[i - 1] != pattern[t - 1])
        {
            t = next[t];
        }

        ++t;
        ++i;

        if(pattern[i - 1] == pattern[t - 1])
        {
            next[i] = next[t];
        }
        else
        {
            next[i] = t;
        }
    }

    while(t > 0 && pattern[i - 1] != pattern[t - 1])
    {
        t = next[t];
    }

    ++t;
    ++i;

    next[i] = t;
}

int kmp( string pattern, string target )
{
    //string pattern = "abcabcacab";
    int pnext[ pattern.size() ]; //= { 0, 1, 1, 0, 1, 1, 0, 5, 0, 1 };
    getnext( pattern, pnext );
    //string target = "babcbabcabcaabcabcabcacabc";
    int con = 0;

    for( int j = 0; j <= target.size() - pattern.size(); )
    {
        int flag = 0;
        int i = 0;
        while( pattern.at( i ) == target.at( j + i ) )
        {
            i++;
            if( i == pattern.size() )
            {
                con++;
                flag = 1;
                break;
            }

        }
        if( flag == 0 )
        {
            j += i + 1 - pnext[ i + 1 ];
            cout << j << endl;
        }
        else
        {
            j++;
        }
    }
    return con;
}

int main()
{
    int n;
    string p, t;

    cin >> n;

    for( int i = 1; i <= n; i++ )
    {
        cin >> p >> t;

        cout << kmp( p, t ) << endl;
    }
}
