/*
ID: 1292871202
LANG: C++
*/
#pragma comment(linker,"/STACK:102400000,102400000")
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <fstream>
using namespace std;

typedef long long ll;

const int INF = 0x3f3f3f3f;
const int MAX = 0x7fffffff;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll LMAX = 0x7fffffffffffffff;
const double eps = 1e-9;
const double pi=acos(-1.0);

const int maxn = 100+5;
const int maxm = 40000+7;
const int mod = 1000000000+7;

#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

void print(char c[3][3])
{
    for(int i=0;i<3;++i)
    {
        for(int j=0;j<3;++j)
        {
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }
}
char aim[3][3]=
{
    '1','2','3',
    '4','5','6',
    '7','8','x',
};
char mp[3][3];
struct State
{
    char d[3][3];
    string ans;
};
vector<State> v[maxm];
int HASH(char a[3][3])
{
    int k=131;
    int ha=0;
    for(int i=0; i<3; ++i)
    {
        for(int j=0; j<3; ++j)
        {
            ha=(ha*k%maxm+a[i][j])%maxm;
        }
    }
    return (ha%maxm+maxm)%maxm;
}

struct node
{
    char d[3][3];
    string s;
};
bool vis(node a)
{
    int ha=HASH(a.d);
    for(int i=0; i<v[ha].size(); ++i)
    {
        bool equ=true;
        for(int j=0; j<3; ++j)
        {
            for(int k=0; k<3; ++k)
            {
                if(a.d[j][k]!=v[ha][i].d[j][k])
                {
                    equ=false;
                    break;
                }
            }
            if(!equ)
                break;
        }
        if(equ)
            return true;
    }
    State newnode;
    for(int i=0; i<3; ++i)
        for(int j=0; j<3; ++j)
            newnode.d[i][j]=a.d[i][j];
    newnode.ans=a.s;
    v[ha].push_back(newnode);
    return false;
}
//r,d,l,u
int dic[4][2]= {0,1,1,0,0,-1,-1,0};
char getStep(int i)
{
    switch(i)
    {
    case 0:
        return 'l';
    case 1:
        return 'u';
    case 2:
        return 'r';
    case 3:
        return 'd';
    }
}
queue<node> q;
void bfs()
{
    for(int i=0;i<maxm;++i)
    {
        v[i].clear();
    }
    while(!q.empty())   q.pop();
    node now,next;
    for(int i=0;i<3;++i)
        for(int j=0;j<3;++j)
            now.d[i][j]=aim[i][j];
    q.push(now);
    now.s="";
    vis(now);
    while(!q.empty())
    {
        now=q.front();  q.pop();
        //print(now.d);
        int nowx,nowy;
        for(int i=0;i<3;++i)
        {
            for(int j=0;j<3;++j)
            {
                if(now.d[i][j]=='x')
                {
                    nowx=i;
                    nowy=j;
                    break;
                }
            }
        }
        for(int i=0;i<4;++i)
        {
            int x=nowx+dic[i][0];
            int y=nowy+dic[i][1];
            //cout<<now.x<<" "<<now.y<<" "<<x<<" "<<y<<endl;
            if(x<0||x>2||y<0||y>2)
                continue;
            swap(now.d[nowx][nowy],now.d[x][y]);
            for(int ii=0;ii<3;++ii)
                for(int jj=0;jj<3;++jj)
                    next.d[ii][jj]=now.d[ii][jj];
            next.s=now.s+getStep(i);

            if(!vis(next))
                q.push(next);
            swap(now.d[nowx][nowy],now.d[x][y]);
        }
    }
}
void slove()
{
    int ha=HASH(mp);
    for(int i=0; i<v[ha].size(); ++i)
    {
        bool equ=true;
        for(int j=0; j<3; ++j)
        {
            for(int k=0; k<3; ++k)
            {
                if(mp[j][k]!=v[ha][i].d[j][k])
                {
                    equ=false;
                    break;
                }
            }
            if(!equ)
                break;
        }
        if(equ)
        {
            //cout<<v[ha][i].ans<<endl;
            for(int ii=v[ha][i].ans.size()-1;ii>=0;--ii)
                cout<<v[ha][i].ans[ii];
            cout<<endl;
            return;
        }
    }
    cout<<"unsolvable"<<endl;
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //cin.sync_with_stdio(false);
    //cout.sync_with_stdio(false);
    bfs();
    while(cin>>mp[0][0])
    {
        cin>>mp[0][1]>>mp[0][2];
        for(int i=1; i<3; ++i)
            for(int j=0; j<3; ++j)
            {
                cin>>mp[i][j];
            }
        slove();
    }
    return 0;
}
