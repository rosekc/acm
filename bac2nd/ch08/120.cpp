//2017-04-21-11.13
//Uva 120

#include <bits/stdc++.h>

using namespace std;

char buf[5000];
int d[150];
int tar[150];
int sized;

void op(int i) {
    int t[sized];
    printf("%d ", i);
    memcpy(t, d, sizeof t);
    for (int j = sized - i; j >= 0; j--) {
        d[j] = t[sized - j - i];
    }
}
void print() {
    for (int i = 0; i < sized; i++) {
        printf("%d ", d[i]);
    }
    puts("");
}
int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    while (gets(buf) == buf) {
        printf("%s\n", buf);
        sized = 0;
        char* pnt = strtok(buf, " ");
        while (pnt != NULL) {
            sscanf(pnt, "%d", &d[sized++]);
            pnt = strtok(NULL, " ");
        }
        memcpy(tar, d, sizeof (int) * sized);
        sort(tar, tar + sized);
        for (int i = sized - 1; i >= 0; i--) {
            if (d[i] != tar[i]) {
                for (int j = i - 1; j >= 0; j--) {
                    if (d[j] == tar[i]) {
                        if (j != 0) op(sized - j);
                        //print();
                        op(sized - i);
                        //print();
                        break;
                    }
                }
            }
        }
        puts("0");
    }
}
