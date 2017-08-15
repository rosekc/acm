#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define ll long long
using namespace std;
const int N = 100000+5;
const int INF = 0x3f3f3f3f;

int T;
bool isr(int y)
{
    return y%400==0 || (y%4==0&&y%100!=0);
}
int main(){
    scanf("%d", &T);
    int y, m, d;
    while (T--)
    {
        scanf("%d-%d-%d", &y,&m,&d);
        bool flag = false;
        if(m==2 && d==29)
            flag = true;
        int ans = 0;
        int t;
        if(m>2 || flag)
            t = y+1;
        else
            t = y;
        int ret = 0;
        while(true)
        {
            if(isr(t))
                ans += 366;
            else
                ans += 365;
            ans %= 7;
            t++;
            ret++;
            if(ans==0 && (!flag||isr(t-1)))
                break;
        }
        printf("%d\n", y+ret);
    }
}
