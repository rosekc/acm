//2017-02-07-18.38
//Uva 11809

#include <bits/stdc++.h>
using namespace std;

double da[10][31];
int db[10][31];
double eps = 1e-4;

void getd()
{
    for (int i = 0; i <= 9; i++)
    {
        for (int j = 1; j <= 30; j++)
        {
            double t = log10(1 - pow(.5, i + 1)) + (pow(2, j) - 1) * log10(2);
            db[i][j] = floor(t);
            da[i][j] = pow(10, t - floor(t));
        }
    }
}
int main()
{
    char in[50];
    double ina;
    int inb;
    getd();
    while (scanf("%s", in) != EOF)
    {
        for (int i = 0; i < strlen(in); i++)
        {
            if (in[i] == 'e') {in[i] = ' '; break;}
        }
        sscanf(in, "%lf%d", &ina, &inb);
        if (ina == 0 && inb == 0) return 0;
        //printf("%f %d\n", ina, inb);
        for (int i = 0; i <= 9; i++)
        {
            for (int j = 1; j <= 30; j++)
            {
                if (abs(da[i][j] - ina) < eps && db[i][j] == inb)
                {
                    printf("%d %d", i, j);
                    goto out;
                }
            }
        }
        out:
            puts("");
    }
}
