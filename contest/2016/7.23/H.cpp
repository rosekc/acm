#include <iostream>

using namespace std;

const int MAX = 5;
char b[ MAX ][ MAX ];
bool ch[ MAX ] [ MAX ];
int t[ MAX ][ MAX ];
int n;

int gett( int x, int y )
{
    int sum = 0;
    int i = x + 1;
    while ( i < n && b[i][y] != 'X' )
    {
        sum++;
        i++;
    }
    i = x - 1;
    while ( i >= 0 && b[i][y] != 'X' )
    {
        sum++;
        i--;
    }
    i = y + 1;
    while ( i < n && b[x][i] != 'X' )
    {
        sum++;
        i++;
    }
    i = y - 1;
    while ( i >= 0 && b[x][i] != 'X' )
    {
        sum++;
        i--;
    }
    return sum;
}
int cht( int x, int y )
{
    int i = x + 1;
    //cout << x<< " " << y << endl;
    while ( i < n && b[i][y] != 'X' )
    {
        if ( ch[i][y] )
        {
            i++;
            continue;
        }
        t[i][y]--;
        i++;
    }
    //cout << "111\n";
    i = x - 1;
    while ( i >= 0 && b[i][y] != 'X' )
    {
        //cout << i << " " << y <<endl;
        if ( ch[i][y] )
        {
            i--;
            continue;
        }
        t[i][y]--;
        i--;
    }
    //cout << "222\n";
    i = y + 1;
    while ( i < n && b[x][i] != 'X' )
    {
        if ( ch[x][i] )
        {
            i++;
            continue;
        }
        t[x][i]--;
        i++;
    }
    //cout << "333\n";
    i = y - 1;
    while ( i >= 0 && b[x][i] != 'X' )
    {
        if ( ch[x][i] )
        {
            i--;
            continue;
        }
        t[x][i]--;
        i--;
    }
}

void setpoint( int x, int y )
{
    ch[x][y] = 1;
    //cout << x << " " << y <<endl;
    int i = x + 1;
    while ( i < n && b[i][y] != 'X' )
    {
        if ( ch[i][y] )
        {
            i++;
            continue;
        }
        //cout << i << " " << y << endl;
        ch[i][y] = 1;
        cht( i, y );
        i++;
    }
    //cout << "111\n";
    i = x - 1;
    while ( i >= 0 && b[i][y] != 'X' )
    {
        if ( ch[i][y] )
        {
            i--;
            continue;
        }
        ch[i][y] = 1;
        cht( i, y );
        i--;
    }
    //cout << "222\n";
    i = y + 1;
    while ( i < n && b[x][i] != 'X' )
    {
        if ( ch[x][i] )
        {
            i++;
            continue;
        }
        ch[x][i] = 1;
        cht( x, i );
        i++;
    }
    //cout << "333\n";
    i = y - 1;
    while ( i >= 0 && b[x][i] != 'X' )
    {
        if ( ch[i][y] )
        {
            i--;
            continue;
        }
        ch[x][i] = 1;
        cht( x, i );
        i--;
    }
    //cout << "1231\n";
}

bool check()
{
    for (int i = 0; i < n; i++ )
    {
        for ( int j = 0; j < n; j++ )
        {
            if ( !ch[i][j] ) return 1;
        }
    }
    return 0;
}

int main()
{
    while (cin >> n && n != 0 )
    {
        int tmin = 7;
        int tr;
        int tc;
        int con = 0;

        for (int i = 0; i < n; i++ )
        {
            for ( int j = 0; j < n; j++ )
            {
                ch[ i ][ j ] = 0;
                cin >> b[ i ][ j ];
            }
        }

        if ( n == 1 )
        {
            if ( b[0][0] == 'X' )
            {
                cout << 0 << endl;
                continue;
            }
            else
            {
                cout << 1 << endl;
                continue;
            }
        }

        for (int i = 0; i < n; i++ )
        {
            for ( int j = 0; j < n; j++ )
            {
                if ( b[i][j] == 'X' )
                {
                    ch[i][j] = 1;
                    t[i][j] = 0;
                    continue;
                }
                t[i][j] = gett( i, j );
                if ( t[i][j] < tmin )
                {
                    tmin = t[i][j];
                    tr = i;
                    tc = j;
                }
            }
        }

        //cout << tr << " " << tc << endl;

        if ( check() )
        {
            setpoint( tr, tc );
            con++;
        }
        //cout << "223";

        while ( check() )
        {
            tmin = 8;
            for (int i = 0; i < n; i++ )
            {
                for ( int j = 0; j < n; j++ )
                {
                    if ( b[i][j] == 'X' || ch[i][j] == 1 )
                    {
                        continue;
                    }
                    if ( t[i][j] < tmin )
                    {
                        tmin = t[i][j];
                        tr = i;
                        tc = j;
                    }
                }
            }
            //cout << ch[ tr ][ tc ]
            //cout << tr << " " << tc << endl;
            setpoint( tr, tc );
            con++;
        }

        cout << con << endl;
    }
}


