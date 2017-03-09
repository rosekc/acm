//2017-02-16-15.32
//Uva 12412

#include <bits/stdc++.h>

using namespace std;
vector<string> menu =
{
    "Welcome to Student Performance Management System (SPMS).",
    "",
    "1 - Add",
    "2 - Remove",
    "3 - Query",
    "4 - Show ranking",
    "5 - Show Statistics",
    "0 - Exit"
};
vector<string> subject =
{
    "Chinese",
    "Mathematics",
    "English",
    "Programming"
};

const int maxn = 1000;
const int maxl = 100;
const double EPS = 1e-5;
int n = 0;
char sid[maxn][maxl];
int cid[maxn];
char name[maxn][maxl];
int score[maxn][5];
bool removed[maxn];

void print_menu()
{
    for (auto s : menu)
    {
        cout << s << endl;
    }
}
void add()
{
    for (;;)
    {
        puts("Please enter the SID, CID, name and four scores. Enter 0 to finish.");
        scanf("%s", sid[n]);
        if (strcmp(sid[n], "0") == 0) return;
        scanf("%d%s%d%d%d%d", &cid[n], name[n],
              &score[n][0], &score[n][1], &score[n][2], &score[n][3]);
        bool f = 1;
        for (int i = 0; i < n; i++) if (!removed[i])
            {
                //printf("%s %s %d\n", sid[n], sid[i], strcmp(sid[n], sid[i]));
                if (strcmp(sid[n], sid[i]) == 0)
                {
                    puts("Duplicated SID.");
                    f = 0;
                    break;
                }
            }
        if (f)
        {
            score[n][4] = score[n][0] + score[n][1] +
                          score[n][2] + score[n][3];
            n++;
        }
    }
}
int getrank(int q)
{
    int re = 1;
    for (int i = 0; i < n; i++) if (!removed[i])
        {
            if (score[q][4] < score[i][4]) re++;
        }
    return re;
}
void DQ(int isq)
{
    char s[maxl];
    for (;;)
    {
        printf("Please enter SID or name. Enter 0 to finish.\n");
        scanf("%s", s);
        if (strcmp(s, "0") == 0) break;
        int r = 0;
        for (int i = 0; i < n; i++) if (!removed[i])
            {
                if (strcmp(sid[i], s) == 0 || strcmp(name[i], s) == 0)
                {
                    if (isq) printf("%d %s %d %s %d %d %d %d %d %.2f\n",
                                        getrank(i), sid[i], cid[i], name[i], score[i][0],
                                        score[i][1], score[i][2], score[i][3], score[i][4],
                                        score[i][4] / 4.0 + EPS);
                    else
                    {
                        removed[i] = 1;
                        r++;
                    }
                }
            }
        if (!isq) printf("%d student(s) removed.\n", r);
    }
}

void stat()
{
    puts("Please enter class ID, 0 for the whole statistics.");
    int in;
    scanf("%d", &in);
    for (int i = 0; i < 4; i++)
    {
        cout << subject[i] << endl;
        int sum = 0;
        int pass = 0, fail = 0, con = 0;
        for (int j = 0; j < n; j++) if (!removed[j] && (!in || cid[j] == in))
            {
                con++;
                sum += score[j][i];
                //printf("%d\n", score[j][i]);
                score[j][i] < 60 ? fail++ : pass++;
            }
        printf("Average Score: %.2f\n", sum / (double) con + EPS);
        printf("Number of passed students: %d\n", pass);
        printf("Number of failed students: %d\n\n", fail);
    }
    puts("Overall:");
    int cnt[5];
    memset(cnt, 0, sizeof cnt);
    for (int j = 0; j < n; j++) if (!removed[j] && (!in || cid[j] == in))
        {
           int t = 0;
           for (int i = 0; i < 4; i++)
           {
               if (score[j][i] >= 60) t++;
           }
           cnt[t]++;
        }
    printf("Number of students who passed all subjects: %d\n", cnt[4]);
    printf("Number of students who passed 3 or more subjects: %d\n", cnt[4] + cnt[3]);
    printf("Number of students who passed 2 or more subjects: %d\n", cnt[4] + cnt[3] + cnt[2]);
    printf("Number of students who passed 1 or more subjects: %d\n", cnt[4] + cnt[3] + cnt[2] + cnt[1]);
    printf("Number of students who failed all subjects: %d\n\n", cnt[0]);
}
int main()
{
    for (;;)
    {
        int choice;
        print_menu();
        scanf("%d", &choice);
        puts("");
        if (choice == 0) break;
        if (choice == 1) add();
        if (choice == 2) DQ(0);
        if (choice == 3) DQ(1);
        if (choice == 4) printf("Showing the ranklist hurts students' self-esteem. Don't do that.\n");
        if (choice == 5) stat();
    }
}
