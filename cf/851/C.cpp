//2017-09-04-23.51
//C

#include <bits/stdc++.h>

using namespace std;

double eps = 1e-7;

struct P {
    int a, b, c, d, e;
    void read() {
        cin >> a >> b >> c >> d >> e;
    }
    P operator - (const P &B)const & {
        return {a-B.a, b-B.b, c-B.c, d-B.d, e-B.e};
    }
};
int dcmp(double x) {
    if (fabs(x) < eps) return 0;
    else return x < 0 ? -1 : 1;
}

int Dot(P A, P B) {
    return A.a * B.a + A.b * B.b + A.c * B.c + A.d * B.d + A.e * B.e;
}
double Length(P A) {
    return sqrt(Dot(A, A));
}
double Angle(P A, P B) {
    return acos(Dot(A, B) / Length(A) / Length(B));
}

P a[1005];
bool gg[1005];
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        a[i].read();
    }
    for (int i = 1; i <= n; i++) {
        if (gg[i]) continue;
        for (int j = i + 1; j <= n; j++) {
            for (int k = j + 1; k <= n; k++) {
                //cout << Angle(a[j] - a[i], a[k] - a[i]) << endl;
                if (dcmp(Angle(a[j] - a[i], a[k] - a[i]) - acos(-1) / 2) >= 0) {
                    gg[j] = gg[k] = 1;
                }else {
                    gg[i] = 1;
                    if (dcmp(Angle(a[i] - a[j], a[k] - a[j]) - acos(-1) / 2) >= 0) {
                        gg[k] = 1;
                    }else {
                        gg[j] = 1;
                        if (dcmp(Angle(a[i] - a[k], a[j] - a[k]) - acos(-1) / 2) < 0) {
                            gg[k] = 1;
                        }
                    }
                }
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!gg[i]) cnt++;
    }
    cout << cnt << endl;
    for (int i = 1; i <= n; i++) {
        if (!gg[i]) cout << i << " ";
    }
    cout << endl;
}
