#include <cstdio>
#include <cstring>

using namespace std;

struct node
{
    int t = -1;
    node* r = NULL;
    node* l = NULL;
};

char re[13];
char re1[13];
//char inre[13];
//char inre1[13];
node* newn;

void addnode(int in, node* cur)
{
    //printf("%d\n", in);
    if (cur->t == -1)
    {
        cur->t = in;
        return;
    }
    if (in > cur->t)
    {
        //printf("456\n");
        if (cur->r == NULL)
        {
            cur->r = new node;
        }
        addnode(in, cur->r);
        return;
    }
    else
    {
        if (cur->l == NULL)
        {
            cur->l = new node;
        }
        addnode(in, cur->l);
        return;
    }
}
int dsize;
void getperorder(node* in, char* re)
{
    re[dsize++] = in->t + '0';
    //printf("%d ", in->t);
    if (in->l != NULL)
    {
        //printf("123");
        getperorder(in->l, re);
    }
    if (in->r != NULL)
    {
        getperorder(in->r, re);
    }
}

void getinorder(node* in, char* re)
{
    if (in->l != NULL)
    {
        //printf("123");
        getperorder(in->l, re);
    }
    re[dsize++] = in->t + '0';
    //printf("%d ", in->t);
    if (in->r != NULL)
    {
        getperorder(in->r, re);
    }
}


int main()
{
    int n;

    while (scanf("%d", &n) != EOF && n)
    {
        char in[15];
        scanf("%s", in);
        newn = new node;

        for (int i = 0; i < strlen(in); i++)
        {
            //printf("%d\n", int(in[i] - '0'));
            addnode(int(in[i] - '0'), newn);
        }

        dsize = 0;
        getperorder(newn, re);
        //printf("\n");
        //re[dsize] = '/0';
        //dsize = 0;
        //getinorder(newn, inre);
        //printf("\n");
        //inre[dsize] = '/0';

        while (n--)
        {
            scanf("%s", in);

            newn = new node;

            for (int i = 0; i < strlen(in); i++)
            {
                addnode(int(in[i] - '0'), newn);
            }
            dsize = 0;
            getperorder(newn, re1);
            //printf("\n");
            //re1[dsize] = '/0';
            //dsize = 0;
            //getinorder(newn, inre1);
            //printf("\n");
            //inre1[dsize] = '/0';

            //printf("%s %s\n", re, re1);

            if (strncmp(re, re1, strlen(in)) == 0) printf("YES\n");
            else printf("NO\n");
        }
    }
}
