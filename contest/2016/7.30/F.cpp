#include <cstdio>
#include <cstring>

using namespace std;

struct node
{
    node* ch[26];
    int con;
    node()
    {
        con = 0;
        for (int i = 0; i < 26; i++)
        {
            ch[i] = NULL;
        }
    }
};

node rt;

int del(char str[], node* n, int i)
{
    if (i == strlen(str) - 1)
    {
        //delete n->ch[str[i] - 'a'];
        if (n->ch[str[i] - 'a'] == NULL) return 0;
        int ret = n->ch[str[i] - 'a']->con;
        n->con -= ret;
        n->ch[str[i] - 'a'] = NULL;
        return ret;
    }
    if (n->ch[str[i] - 'a'] == NULL) return 0;
    int ret = del(str, n->ch[str[i] - 'a'], i + 1);
    n->con -= ret;
    //printf("%d\n", ret);
    if (n->ch[str[i] - 'a']->con == 0)
    {
        n->ch[str[i] - 'a'] = NULL;
        //printf("1230\n");
    }
    return ret;
}

void ins(char str[], node* n, int i)
{
    n->con++;
    if (i == strlen(str))
    {
        return;
    }
    if (n->ch[str[i] - 'a'] == NULL)
    {
        n->ch[str[i] - 'a'] = new node;
    }
    ins(str, n->ch[str[i] - 'a'], i + 1);
}

bool sea(char* str, node* n, int i)
{
    if (n->ch[str[i] - 'a'] == NULL || n->con == 0)
    {
        return 0;
    }
    if (i == strlen(str) - 1)
    {
        return 1;
    }
    sea(str, n->ch[str[i] - 'a'], i + 1);
}

int main()
{
    int t;
    char in[10];
    char str[40];
    scanf("%d", &t);
    while (t--)
    {
        scanf("%s %s", in, str);
        if (in[0] == 'i')
        {
            ins(str, &rt, 0);
        }
        else if (in[0] == 's')
        {
            if(sea(str, &rt, 0)) printf("Yes\n");
            else printf(("No\n"));
        }
        else if (in[0] == 'd')
        {
            del(str, &rt, 0);
        }
    }
}
