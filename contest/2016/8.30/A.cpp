#include <cstdio>
#include <cmath>
int main()
{
    const double PI = acos(-1);
    int r;
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &r);
        double a = r;
        double b = .5 * r;
        double c = sqrt(b * b + b * b);
        //printf("%lf %lf %lf\n", a, b, c);
        //printf("%lf\n", PI);
        double cosa = (b * b + c * c - a * a) / (2 * b * c);
        double cosb = (a * a + c * c - b * b) / (2 * a * c);
        //printf("%lf %lf", acos(cosa) / PI * 180, acos(cosb) / PI * 180);
        double s0 = (2 * acos(cosb) / (2 * PI)) * PI * a * a;
        double p = .5 * (a + b + c);
        double s1 = 2 * sqrt(p * (p - a) * (p - b) * (p - c));
        double s2 = s0 - s1;
        double s3 = ((2 * (PI - acos(cosa))) / (2 * PI)) * PI * b * b;
        printf("%.2f\n", 2 * (s3 - s2));
    }
}
