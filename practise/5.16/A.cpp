//2017-05-16-22.50
//???

#include <bits/stdc++.h>

using namespace std;

const int maxn = 10e6 + 10;
int lu[maxn], rd[maxn];
//lu��ʾ1-i�ĵĸ�����rd��ʾi-n�ĸ��������ϻ�������汾���壬ͬ������
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
    //tά�����ǵ�ǰ�������Ԫ�ض�i�ľ��룬����ǰ׺�ͣ����ٺܶ�����Ѷ�
    for (int i = 1; i <= n; i++) {
        t += que.size();
        //���������Ҫ������u����
        //����que�����Ԫ�ز������lu��ֵ����rd�ǵݼ���
        //����������rdȥ�ȣ�ʡȥ�˸���ȡmin�ĺ���
        //ֵ��һ�����lu���que��Ԫ�ش�ֱ���������鷳�����������
        while (que.size() > rd[i]) {
            t -= (i - que.front());
            que.pop();
        }
        ans[i] += t * 2;//Ҫ���أ����Գ�2����ͼ�Ͷ���
        if (s[i] == 'U') {
            que.push(i);
        }
    }
    while (!que.empty()) que.pop();
    t = 0;
    //����ͬ��
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
