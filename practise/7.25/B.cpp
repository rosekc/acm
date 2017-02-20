#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

struct node
{
    int con;
    node* child[26];
    node()
    {
        con = 0;
        for (int i = 0; i < 26; i++) child[i] = NULL;
    }
};

node root;
node* cur;
node* newn;

void builtNode(char* str)
{
    cur = &root;
    for (int i = 0; i < strlen(str); i++)
    {
        int tmp = str[i] - 'a';
        if (cur->child[tmp] != NULL)
        {
            cur = cur->child[tmp];
            cur->con++;
        }
        else
        {
            newn = new node;
            newn->con++;
            cur->child[tmp] = newn;
            cur = newn;
        }
    }
}

int searchNode(char* str)
{
    cur = &root;
    for (int i = 0; i < strlen(str); i++)
    {
        int tmp = str[i] - 'a';
        if (cur->child[tmp] != NULL)
        {
            cur = cur->child[tmp];
        }
        else
        {
            return 0;
        }
    }
    return cur->con;
}

int main()
{
    char tmp[12];
    int i = 0;

    while (gets(tmp) != NULL && strlen(tmp) != 0)
    {
        builtNode(tmp);
    }

    while (gets(tmp) != NULL)
    {
        printf("%d\n", searchNode(tmp));
    }
}
