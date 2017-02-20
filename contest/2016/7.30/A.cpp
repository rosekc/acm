#include <iostream>
#include <string>

using namespace std;

struct data
{
    string team;
    int t;
};

data a[22];

int main()
{
    a[0].t = 1;
    a[1].t = 17;
    a[2].t = 6;
    a[3].t = 1;
    a[4].t = 1;
    a[5].t = 3;
    a[6].t = 2;
    a[7].t = 2;
    a[8].t = 11;
    a[9].t = 3;
    a[10].t = 1;
    a[11].t = 5;
    a[12].t = 2;
    a[13].t = 2;
    a[14].t = 2;
    a[15].t = 1;
    a[16].t = 1;
    a[17].t = 5;
    a[18].t = 1;
    a[19].t = 1;
    a[20].t = 1;
    a[21].t = 1;
    a[0].team = "Baltimore Bullets";
    a[1].team = "Boston Celtics";
    a[2].team = "Chicago Bulls";
    a[3].team = "Cleveland Cavaliers";
    a[4].team = "Dallas Mavericks";
    a[5].team = "Detroit Pistons";
    a[6].team = "Golden State Warriors";
    a[7].team = "Houston Rockets";
    a[8].team = "L.A. Lakers";
    a[9].team = "Miami Heat";
    a[10].team = "Milwaukee Bucks";
    a[11].team = "Minneapolis Lakers";
    a[12].team = "New York Knicks";
    a[13].team = "Philadelphia 76ers";
    a[14].team = "Philadelphia Warriors";
    a[15].team = "Portland Trail Blazers";
    a[16].team = "Rochester Royals";
    a[17].team = "San Antonio Spurs";
    a[18].team = "Seattle Sonics";
    a[19].team = "St. Louis Hawks";
    a[20].team = "Syracuse Nats";
    a[21].team = "Washington Bullets";
    int t;
    string str;
    int con = 1;
    char c;
    cin >> t;
    t++;
    //cin >> c;
    while (t--)
    {
        getline(cin, str, '\n');
        if(str == "") continue;
        //cout << str << "\n";
        for (int i = 0; i <= 21; i++)
        {
            if (str == a[i].team)
            {
                cout << "Case #"<< con++ << ": "<< a[i].t << endl;
                break;
            }
            if(i == 21) cout << "Case #"<< con++ << ": 0\n";
        }
    }
}
