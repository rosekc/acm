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
    char str[100];

    scanf("%d", &t);
    while (scanf("%s", str))
    {

    }
}
