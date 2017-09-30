//2017-09-24-14.42
//A

#include <bits/stdc++.h>

using namespace std;

double a[5][5];
int s[100000];
char buf[999999];
void cal1() {
    gets(buf);
    char *t = strtok(buf, " ");
    int i = 0;
    //cout << t << endl;
    while (t != NULL) {
        sscanf(t, "%d", &s[i]);
        //cout << s[i] << endl;
        i++;
        t = strtok(NULL, " ");
    }
    double ans = 1;
    //cout << i << endl;
    for (int j = 0; j < i - 1; j++) {
        //cout << s[j] <<endl;
        ans *= a[s[j]][s[j + 1]];
        //cout <<ans << endl;
    }
    printf("%.8f\n", ans);
}
void cal2() {
    int t;
    cin >> t;
    double p = 1;
    double ans = 0;
    while (p >= 1e-9) {
        ans += p;
        p *= a[t][t];
    }
    printf("%.8f\n", ans);
}
int main() {
    for (int i = 1; i <= 4; i++) {
        for(int j = 1; j <= 4; j++) {
            cin >> a[i][j];
        }
    }
    getchar();
    cal1();
    cal1();
    cal2();
    cal2();
}
