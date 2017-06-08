#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

const int maxn = 100 + 10;
struct data
{
    string str;
};
data s1[maxn];
data s2[maxn];
int dp[maxn][maxn];
int re[maxn];
int n, m;
stack<int> sta;
int lcs(int i, int j)
{
    if (dp[i][j] != -1) return dp[i][j];
    if (i == 0 || j == 0)
    {
        dp[i][j] = 0;
        return 0;
    }
    if (s1[i].str == s2[j].str)
    {
        dp[i][j] = lcs(i - 1, j - 1) + 1;
        return dp[i][j];
    }
    else
    {
        if (lcs(i - 1, j) > lcs(i, j - 1))
        {
            dp[i][j] = lcs(i - 1, j);
        }
        else
        {
            dp[i][j] = lcs(i, j - 1);
        }
        return dp[i][j];
    }
}
void getlcs(int i, int j)
{
    if (i == 0 || j == 0) return;
    if (dp[i][j] == dp[i - 1][j])
    {
        getlcs(i - 1, j);
        return;
    }
    if (dp[i][j] == dp[i][j - 1])
    {
        getlcs(i, j - 1);
        return;
    }
    if (dp[i][j] - 1 == dp[i - 1][j - 1])
    {
        sta.push(i);
        getlcs(i - 1, j - 1);
        return;
    }
}
bool readstr()
{
    memset(dp, -1, sizeof(dp));
    n = 1;
    m = 1;
    if (cin >> s1[n].str) n++;
    else return 0;
    while (cin >> s1[n].str && s1[n].str != "#" ) n++;
    while (cin >> s2[m].str && s2[m].str != "#" ) m++;
    n--;
    m--;
    return 1;
}
int main()
{
    ios::sync_with_stdio(0);
    while (readstr())
    {
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                lcs(i, j);
                //cout << lcs(i, j) << " ";
            }
            //cout << "\n";
        }
        getlcs(n, m);
        while (1)
        {
            cout << s1[sta.top()].str;
            sta.pop();
            if (!sta.empty()) cout << " ";
            else
            {
                cout << endl;
                break;
            }
        }
    }
}
