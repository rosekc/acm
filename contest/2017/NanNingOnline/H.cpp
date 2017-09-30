//2017-09-24-12.11
//H

#include <bits/stdc++.h>

using namespace std;

int cache[64];
char buf[20];
int main() {
    int mask = (1 << 7) - 1;
    memset(cache, 0xff, sizeof cache);
    int hit = 0, cnt = 0;
    int a = 0;
    while (scanf("%s", buf)) {
        if (buf[1] == 'N') {
            //cout << hit << " " << cnt << endl;
            printf("Hit ratio = %.2f", hit * 100.0 / cnt);
            cout << "%" << endl;
            return 0;
        }
        cnt++;
        //cout << buf << endl;
        sscanf(buf, "%x", &a);
        int line = (a / 16) % 64;
        int tag = a / 1024;
        //printf("%x\n%x\n", line, tag);
        //cout << cache[line] <<endl;
        if (cache[line] == tag) {
            hit++;
            puts("Hit");
        }else {
            puts("Miss");
            cache[line] = tag;
        }
    }
}
