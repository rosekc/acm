#include <iostream>
#include <queue>
using namespace std;

struct d
{
    int r;
    int c;
    int con;
    bool isgr;
};
queue<d>q;
const int MAX = 205;
int mr[ 4 ] = { -1, 0, 1, 0};
int mc[4] = {0, 1, 0, -1};
char b[ MAX ][ MAX ];
int t[ MAX ][ MAX ];
int r, c;


int bfs()
{
    while ( !q.empty() )
    {
        if ( q.front().isgr )
        {
            q.push( { q.front().r, q.front().c, q.front().con + 1, 0 } );
            q.pop();
            continue;
        }
        for ( int i = 0; i < 4; i++)
        {
            int tr = q.front().r + mr[i];
            int tc = q.front().c + mc[i];

            if ( tr >= 0 && tr < r && tc >= 0 && tc < c
                    && b[tr][tc] != '#' && t[tr][tc] > q.front().con )
            {
                bool flag = 0;
                int tt =q.front().con + 1;
                if ( b[tr][tc] == 'a' )
                {
                    return tt;
                }
                if ( b[tr][tc] == 'x' )
                {
                    flag = 1;
                }
                t[tr][tc] = tt;
                q.push( { tr, tc, tt, flag } );
            }
        }
        q.pop();
    }
    return -1;
}

int main()
{
    while (cin >> r >> c)
    {
        for (int i = 0; i < r; i++ )
        {
            for ( int j = 0; j < c; j++ )
            {
                t[ i ][ j ] = 50000;
                cin >> b[ i ][ j ];;
                if ( b[i][j] == 'r' )
                {
                    t[i][j] = 0;
                    q.push( { i, j, 0, 0 });
                }
            }
        }

        int re = bfs();

        if( re == -1 )
        {
            cout << "Poor ANGEL has to stay in the prison all his life.\n";
        }
        else
            cout << re << endl;
        while( !q.empty() ) q.pop();
    }
}
