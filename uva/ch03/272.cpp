//2016-09-26-00.03
//Uva 272

#include <cstdio>
using namespace std;

int main()
{
    bool f = 1;
    char c;
    while ((c = getchar()) != EOF)
    {
        if (c == '"') {printf("%s", f ? "``" : "''"); f = !f;}
        else printf("%c", c);
    }
}
