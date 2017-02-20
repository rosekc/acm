#include<stdio.h>
//#include<bits/stdc++.h>
#include<string.h>
#include<iostream>
#include<math.h>
#include<sstream>
#include<set>
#include<queue>
#include<map>
#include<vector>
#include<algorithm>
#include<limits.h>
#define inf 0x3fffffff
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define LL long long
using namespace std;
int mod=1e9+7;
LL n,m;
LL ans=1;
LL num=1;
int main()
{
    while(cin>>n>>m)
    {
        LL e=1;
        ans=1;
        num=1;
        while(n--)
        {
            LL pos=(e<<n);
            if(m<=pos)
            {
                num++;
             //   cout<<"A"<<endl;
            }
            else
            {
                num+=2*pos;
                m-=pos;
                //cout<<"B"<<endl;
            }
           // cout<<x<<endl;
            ans+=num;
            ans%=mod;
        }
        cout<<ans%mod<<endl;
    }
    return 0;
}
