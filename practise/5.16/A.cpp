//2017-05-16-22.50
//???

#include <bits/stdc++.h>

using namespace std;

const int maxn = 10e6 + 10;
int lu[maxn], rd[maxn];
//lu表示1-i的的个数，rd表示i-n的个数。网上还有另外版本定义，同样道理
long long ans[maxn];
queue<int> que;
int n;
char s[maxn];

int main() {
    cin >> n >> s + 1;
    for (int i = 1; i <= n; i++) {
        lu[i] = lu[i - 1] + (s[i] == 'U');
    }
    for (int i = n; i >= 1; i--) {
        rd[i] = rd[i + 1] + (s[i] == 'D');
    }
    for (int i = 1; i <= n; i++) {
        if (lu[i] <= rd[i + 1]) ans[i] = i;
        else ans[i] = n - i + 1;
    }
    long long t = 0;
    //t维护的是当前队列里的元素对i的距离，不用前缀和，减少很多调试难度
    for (int i = 1; i <= n; i++) {
        t += que.size();
        //这里求左边要遇到的u个数
        //明显que里面的元素不会大于lu的值，而rd是递减的
        //这里巧妙用rd去比，省去了各种取min的函数
        //值得一提的是lu会比que的元素大，直接算好像好麻烦，不如这里简单
        while (que.size() > rd[i]) {
            t -= (i - que.front());
            que.pop();
        }
        ans[i] += t * 2;//要来回，所以乘2，画图就懂了
        if (s[i] == 'U') {
            que.push(i);
        }
    }
    while (!que.empty()) que.pop();
    t = 0;
    //下面同理
    for (int i = n; i >= 1; i--) {
        t += que.size();
        while (que.size() > lu[i]) {
            t -= (que.front() - i);
            que.pop();
        }
        ans[i] += t * 2;
        if (s[i] == 'D') {
            que.push(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}
