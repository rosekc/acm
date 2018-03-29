#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

typedef  long long ll;
string s;
ll t;
ll  get_int(int l, int r){
    ll ans=0;
    while(l<=r){
        ans*=10;
        ans+=s[l]-'0';
        l++;
    }
    return ans;
}

main(){
    ios::sync_with_stdio(false);
    cin>>t;
    int k=1;
    while(t--){
        cin>>s;
        int len=s.length();
        ll ans=-INF;
        for(int i=1;i<len-3;i++){
            ll aa=s[0]-'0',bb=s[i]-'0';
            aa+=get_int(1,i);
            bb+=get_int(0,i-1);
            ll cnt=max(aa,bb);
            ll c=s[i+1]-'0';
            ll d=s[i+2]-'0';
            ll e= get_int(i+3,len-1);
            ans=max(ans,cnt-c*d/e);
        }
        cout<<"Case #"<<k++<<": "<<ans<<endl;
    }


}
