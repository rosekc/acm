//2017-04-22-18.05
//E

#include <bits/stdc++.h>

using namespace std;

char in1[10];
int d[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6, 6, 5, 4, 5, 5, 4};

int cal(char* in) {
    int re = 0;
    for (int i = 0; i < 8; i++) {
        //cout << re << endl;
        //cout << i << endl;
        if (in[i] >= '0' && in[i] <= '9') {
            re += d[in[i] - '0'];

        }else  {
            //cout << in[i] - 'a' + 10 << endl;
            re += d[in[i] - 'a' + 10];
        }
    }
    return re;
}

int main()
{
    int T, n;
    unsigned int in;
    cin >> T;

    while (T--) {
        scanf("%d %x", &n, &in);
        long long re = 0;
        for (int i = 0; i < n; i++) {
            sprintf(in1, "%08x", in);
            //cout << in1 << endl;
            re += cal(in1);
            //cout << re << endl;
            in++;
        }
        printf("%lld\n", re);
    }
}
