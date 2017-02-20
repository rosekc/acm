#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
struct point
{
    int x, y;
};
double dist(point a, point b, int v)
{
    return sqrt((abs(a.x - b.x) * abs(a.x - b.x)) + (abs(a.y - b.y) * abs(a.y - b.y))) / v;
}
int main()
{
    point st;
    double mint = 0x3f3f3f3f;
    scanf("%d%d", &st.x, &st.y);
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int v;
        point ed;
        scanf("%d%d%d", &ed.x, &ed.y, &v);
        mint = min(mint, dist(st, ed, v));
        //printf("%lf\n", dist(st, ed, v));
    }
    printf("%.20lf\n", mint);
}
